//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define KEY 12345

int main(int argc, char *argv[])
{
    int shmid;
    int *shmptr;
    int my_id = getpid();
    int num_players = 0;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error: could not create shared memory segment.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = (int*) shmat(shmid, NULL, 0);
    if (shmptr == (int*) -1)
    {
        printf("Error: could not attach to shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++)
    {
        *(shmptr + i) = 0;
    }

    // Wait for other players to join
    while (num_players < SIZE)
    {
        sleep(1);
        num_players = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (*(shmptr + i)!= 0)
            {
                num_players++;
            }
        }
    }

    // Game loop
    while (1)
    {
        int target_player = rand() % SIZE;
        int my_move = rand() % 3; // 0 = rock, 1 = paper, 2 = scissors
        int target_move = *(shmptr + target_player);

        // Determine winner
        if (my_move == 0 && target_move == 2)
        {
            *(shmptr + my_id) += 1;
        }
        else if (my_move == 1 && target_move == 0)
        {
            *(shmptr + my_id) += 1;
        }
        else if (my_move == 2 && target_move == 1)
        {
            *(shmptr + my_id) += 1;
        }
        else
        {
            *(shmptr + target_player) += 1;
        }

        // Check for winner
        int max_score = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (*(shmptr + i) > max_score)
            {
                max_score = *(shmptr + i);
            }
        }
        if (max_score >= 5)
        {
            printf("Player %d wins!\n", max_score);
            break;
        }
    }

    // Detach from shared memory segment
    if (shmdt(shmptr) == -1)
    {
        printf("Error: could not detach from shared memory segment.\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Error: could not delete shared memory segment.\n");
        exit(1);
    }

    return 0;
}
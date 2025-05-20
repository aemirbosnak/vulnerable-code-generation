//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_DISKS 10

int num_disks;
pthread_mutex_t tower_1, tower_2, tower_3;

void move_disk(int disk, int from_tower, int to_tower)
{
    printf("Moving disk %d from Tower %d to Tower %d.\n", disk, from_tower, to_tower);
}

void* transfer_towers(void* arg)
{
    int* i = (int*)arg;
    int disk = *i;
    if (disk % 2 == 0)
    {
           pthread_mutex_lock(&tower_1);
           pthread_mutex_lock(&tower_3);
           move_disk(disk, 1, 3);
           pthread_mutex_unlock(&tower_3);
           pthread_mutex_unlock(&tower_1);
    }
    else
    {
           pthread_mutex_lock(&tower_1);
           pthread_mutex_lock(&tower_2);
           move_disk(disk, 1, 2);
           pthread_mutex_unlock(&tower_2);
           pthread_mutex_unlock(&tower_1);
           pthread_mutex_lock(&tower_2);
           pthread_mutex_lock(&tower_3);
           move_disk(disk, 2, 3);
           pthread_mutex_unlock(&tower_3);
           pthread_mutex_unlock(&tower_2);
    }
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[MAX_DISKS];
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks > MAX_DISKS)
    {
        printf("Please enter a number less than or equal to 10.\n");
        exit(1);
    }
    pthread_mutex_init(&tower_1, NULL);
    pthread_mutex_init(&tower_2, NULL);
    pthread_mutex_init(&tower_3, NULL);
    int disks[MAX_DISKS];
    for (i = 0; i < num_disks; i++)
    {
        disks[i] = i + 1;
    }
    for (i = 0; i < num_disks; i++)
    {
        pthread_create(&threads[i], NULL, transfer_towers, &disks[i]);
    }
    for (i = 0; i < num_disks; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&tower_1);
    pthread_mutex_destroy(&tower_2);
    pthread_mutex_destroy(&tower_3);
    return 0;
}
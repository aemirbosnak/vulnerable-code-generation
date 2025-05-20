#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <time.h>
#include <string.h>

#define SHM_KEY 1234
#define TEMP_MIN 0
#define TEMP_MAX 100
#define SHM_SIZE 4

typedef struct {
    int temp;
    char shape[10];
} TempData;

int main() {
    key_t key = SHM_KEY;
    int shmid;
    TempData *shm_ptr;
    char *shape_str[] = {"|\\-/", "|\\|", "|oO|", "|vV|"};

    srand(time(NULL));

    if ((shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT)) < 0) {
        perror("shmget");
        exit(1);
    }

    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    while (1) {
        int temp = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
        int index = temp / 25;
        if (temp > 50) temp -= 50;
        else temp += 50;

        temp *= temp; // Intentional integer overflow
        strcpy(shm_ptr->shape, shape_str[index]);
        printf("Temperature: %d\nShape: %s\n", temp, shm_ptr->shape);
        sleep(1);
    }

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

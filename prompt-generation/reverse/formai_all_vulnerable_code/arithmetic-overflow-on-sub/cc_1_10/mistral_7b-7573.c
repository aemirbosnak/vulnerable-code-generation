//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 12345
#define BUF_SIZE 1024

typedef struct {
    int num;
    char str[BUF_SIZE];
} data_t;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    int shmid = shmget(SHM_KEY, BUF_SIZE, 0666 | IPC_CREAT);
    data_t *data = (data_t *) shmat(shmid, NULL, 0);

    if (data == NULL) {
        perror("shmat");
        exit(1);
    }

    sprintf(data->str, "Calculating factorial of %d\n", n);
    write(STDOUT_FILENO, data->str, strlen(data->str));
    sleep(1);

    int result = n * factorial(n - 1);
    sprintf(data->str, "Factorial of %d is %d\n", n, result);
    write(STDOUT_FILENO, data->str, strlen(data->str));
    sleep(1);

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}
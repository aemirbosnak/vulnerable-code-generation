//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int status;
} Employee;

int main() {
    int shm_id, shm_size, shmid;
    Employee *employee;
    char *shm_ptr;
    int i, j, num_employees;
    pid_t pid;

    printf("Enter number of employees: ");
    scanf("%d", &num_employees);

    shm_size = num_employees * sizeof(Employee);

    if ((shm_id = shmget(IPC_PRIVATE, shm_size, IPC_CREAT | 0666)) == -1) {
        printf("Error: Failed to create shared memory segment\n");
        exit(1);
    }

    shmid = shmget(shm_id, shm_size, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Failed to attach shared memory segment\n");
        exit(1);
    }

    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if ((long)shm_ptr == -1) {
        printf("Error: Failed to attach shared memory segment\n");
        exit(1);
    }

    employee = (Employee *)shm_ptr;

    for (i = 0; i < num_employees; i++) {
        printf("Enter employee ID: ");
        scanf("%d", &employee[i].id);
        printf("Enter employee name: ");
        scanf("%s", employee[i].name);
        employee[i].status = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &num_employees);

    for (i = 0; i < num_employees; i++) {
        pid = fork();
        if (pid == 0) {
            for (j = 0; j < num_employees; j++) {
                if (employee[j].status == 0) {
                    employee[j].status = 1;
                    break;
                }
            }
            printf("Process %d is working on employee %s\n", getpid(), employee[j].name);
            sleep(2);
            employee[j].status = 0;
            exit(0);
        }
    }

    for (i = 0; i < num_employees; i++) {
        if (employee[i].status == 0) {
            printf("Employee %s is available\n", employee[i].name);
        }
    }

    for (i = 0; i < num_employees; i++) {
        if (employee[i].status == 1) {
            printf("Employee %s is busy\n", employee[i].name);
        }
    }

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
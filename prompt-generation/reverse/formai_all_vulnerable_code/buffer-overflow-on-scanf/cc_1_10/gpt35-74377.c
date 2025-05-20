//FormAI DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27 // Size of shared memory segment

int rSum(int arr[], int n);
int lSum(int *arr, int n);

int main()
{
    int *arr;
    int shmid;
    key_t key = 5678;

    // Create shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to address space
    if ((arr = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read user input and populate array
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter elements in array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate left and right sums recursively
    int lsum = lSum(arr, n/2);
    int rsum = rSum(arr+(n/2), n - n/2);

    // Display result
    printf("Left sum = %d\nRight sum = %d\n", lsum, rsum);

    // Detach and delete shared memory segment
    shmdt(arr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

int rSum(int arr[], int n)
{
    if (n == 1) {
        return arr[0];
    } else {
        int sum = rSum(arr, n/2) + rSum(arr+(n/2), n - n/2);
        return sum;
    }
}

int lSum(int *arr, int n)
{
    if (n == 1) {
        return *arr;
    } else {
        int sum = lSum(arr, n/2) + rSum(arr+(n/2), n - n/2);
        return sum;
    }
}
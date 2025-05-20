//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

// Structure for passing data between threads
struct v {
    int top;
    int from;
    int to;
    int *a;
};

// Function to print the disks
void print_disks(int disk, int from, int to, int *a) {
    int i;
    for (i = 0; i <= disk; i++) {
        if (i == disk)
            printf("%d ", a[i]);
        else
            printf("- ");
    }
    printf("\n");
}

// Function to move the disks
void move_disk(int n, int from, int to, int *a) {
    int i;
    for (i = n; i >= 1; i--) {
        a[to] = a[from];
        from--;
        to++;
    }
    a[to] = a[from];
}

// Function executed by each thread
void *runner(void *param) {
    struct v *v = (struct v *) param;
    int n = v->top;
    int from = v->from;
    int to = v->to;
    int *a = v->a;

    // Base case
    if (n == 1) {
        move_disk(1, from, to, a);
        printf("Moved disk 1 from rod %d to rod %d\n", from, to);
        return NULL;
    }

    // Recursive case
    move_disk(n - 1, from, to - 1, a);
    move_disk(1, from, to, a);
    move_disk(n - 1, to, from - 1, a);

    return NULL;
}

// Main function
int main() {
    pthread_t threads[MAX];
    int i, n, from, to;
    int a[MAX];

    // Initialize the rods with disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    for (i = n; i >= 1; i--) {
        printf("Enter the position of disk %d: ", i);
        scanf("%d", &a[i]);
    }

    // Initialize the threads
    for (i = 0; i < n; i++) {
        struct v v;
        v.top = n;
        v.from = 0;
        v.to = i;
        v.a = a;
        pthread_create(&threads[i], NULL, runner, &v);
    }

    // Join the threads
    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All disks moved to rod %d\n", n - 1);

    return 0;
}
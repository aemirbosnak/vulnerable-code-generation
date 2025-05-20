//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>

// Function to move disks from source peg to destination peg using third peg as a temporary storage area
void move(int n, int source, int destination, int third) {
    // Base case: If there is only one disk
    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source peg to third peg
    move(n-1, source, third, destination);
    
    // Move the last disk from source peg to destination peg
    printf("Move disk %d from peg %d to peg %d\n", n, source, destination);
    
    // Move the n-1 disks from third peg to destination peg
    move(n-1, third, destination, source);
}

// Function to move disks from source peg to destination peg
void move_disks(int n, int source, int destination) {
    move(n, source, destination, -1);
}

// Function to print disks on the given peg
void print_disks(int peg) {
    int i;
    for (i = 1; i <= peg; i++) {
        printf("Disk %d\n", i);
    }
}

int main(int argc, char **argv) {
    int n, peg;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the peg number: ");
    scanf("%d", &peg);
    
    print_disks(peg);
    
    move_disks(n, peg, peg);
    
    print_disks(peg);
    
    move_disks(n, peg, peg);
    
    print_disks(peg);
    
    printf("end\n");
    
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_disks, current_pole, temp_pole;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("Enter the current pole: ");
    scanf("%d", &current_pole);
    printf("Enter the temporary pole: ");
    scanf("%d", &temp_pole);

    printf("\n");

    int disks[num_disks];
    int i;

    printf("Enter the disks: ");
    for(i = 0; i < num_disks; i++) {
        scanf("%d", &disks[i]);
    }

    printf("\n");

    for(i = num_disks - 1; i > 0; i--) {
        printf("%d from %d to %d\n", disks[i], current_pole, temp_pole);
        temp_pole = current_pole;
        current_pole = temp_pole - 1;
        if(temp_pole == 0) {
            current_pole = temp_pole;
        }
        printf("\n");
        printf("%d from %d to %d\n", disks[i], current_pole, temp_pole);
        temp_pole = current_pole;
        current_pole = temp_pole + 1;
        if(temp_pole == num_disks) {
            current_pole = temp_pole;
        }
        printf("\n");
        printf("%d from %d to %d\n", disks[i], current_pole, temp_pole);
        temp_pole = current_pole;
        current_pole = temp_pole + 1;
        if(temp_pole == num_disks) {
            current_pole = temp_pole;
        }
        printf("\n");
    }

    return 0;
}
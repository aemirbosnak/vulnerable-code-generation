//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 100
#define MAX_DISK_NAME 50

typedef struct {
    char name[MAX_DISK_NAME];
    long long total_space;
    long long used_space;
    long long free_space;
    double percent_used;
} Disk;

void read_disks(Disk disks[], int num_disks) {
    system("df -h | awk '{print $1, $2, $3, $4, $5}' > disks.txt");
    FILE *file = fopen("disks.txt", "r");
    if (file == NULL) {
        printf("Error: Could not read disk information.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s %lld %lld %lld %lf\n", disks[i].name, &disks[i].total_space, &disks[i].used_space, &disks[i].free_space, &disks[i].percent_used) == 5) {
        i++;
        if (i >= num_disks) {
            printf("Warning: Not all disks were analyzed.\n");
            break;
        }
    }
    fclose(file);
    remove("disks.txt");
}

void print_disks(Disk disks[], int num_disks) {
    printf("Disk\tTotal\tUsed\tFree\tPercent\n");
    for (int i = 0; i < num_disks; i++) {
        printf("%s\t%lld\t%lld\t%lld\t%.2lf%%\n", disks[i].name, disks[i].total_space, disks[i].used_space, disks[i].free_space, disks[i].percent_used);
    }
}

int main() {
    int num_disks = 0;
    while (num_disks == 0 || num_disks > MAX_DISKS) {
        printf("Enter number of disks to analyze (1-%d): ", MAX_DISKS);
        scanf("%d", &num_disks);
    }
    Disk disks[num_disks];
    read_disks(disks, num_disks);
    print_disks(disks, num_disks);
    return 0;
}
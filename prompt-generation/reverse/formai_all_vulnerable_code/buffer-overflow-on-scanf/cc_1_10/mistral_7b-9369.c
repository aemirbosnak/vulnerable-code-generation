//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

typedef struct {
    int steps;
    int calories;
    float distance;
} FitnessData;

void save_data(FitnessData data) {
    int fd = open("fitness.dat", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    write(fd, &data, sizeof(FitnessData));
    close(fd);
}

void load_data(FitnessData *data) {
    int fd = open("fitness.dat", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    read(fd, data, sizeof(FitnessData));
    close(fd);
}

int main() {
    FitnessData data;
    int choice;

    while (1) {
        printf("\nPeaceful Fitness Tracker\n");
        printf("1. Record new data\n");
        printf("2. Display last recorded data\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &data.steps);
                printf("Enter number of calories burned: ");
                scanf("%d", &data.calories);
                printf("Enter distance in kilometers: ");
                scanf("%f", &data.distance);
                save_data(data);
                printf("Data saved.\n");
                break;
            case 2:
                load_data(&data);
                printf("Steps: %d\n", data.steps);
                printf("Calories: %d\n", data.calories);
                printf("Distance: %.2f km\n", data.distance);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
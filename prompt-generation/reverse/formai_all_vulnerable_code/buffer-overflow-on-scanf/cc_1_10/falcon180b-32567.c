//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA 100
#define MAX_NAME 50
#define MAX_ACTIVITY 50

struct Data {
    char name[MAX_NAME];
    char activity[MAX_ACTIVITY];
    int steps;
    int calories;
};

void read_data(struct Data *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);
    printf("Enter your activity: ");
    scanf("%s", data->activity);
    printf("Enter the number of steps: ");
    scanf("%d", &data->steps);
    printf("Enter the number of calories burned: ");
    scanf("%d", &data->calories);
}

void print_data(struct Data *data) {
    printf("Name: %s\n", data->name);
    printf("Activity: %s\n", data->activity);
    printf("Steps: %d\n", data->steps);
    printf("Calories burned: %d\n", data->calories);
}

void save_data(struct Data *data, FILE *file) {
    fprintf(file, "%s %s %d %d\n", data->name, data->activity, data->steps, data->calories);
}

void load_data(struct Data *data, FILE *file) {
    char buffer[100];
    fscanf(file, "%s %s %d %d", data->name, data->activity, &data->steps, &data->calories);
}

int main() {
    char filename[MAX_NAME];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    struct Data data;
    int choice;
    do {
        printf("\n1. Enter new data\n2. Print data\n3. Save data to file\n4. Load data from file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            read_data(&data);
            break;
        case 2:
            print_data(&data);
            break;
        case 3:
            save_data(&data, file);
            break;
        case 4:
            load_data(&data, file);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    fclose(file);
    return 0;
}
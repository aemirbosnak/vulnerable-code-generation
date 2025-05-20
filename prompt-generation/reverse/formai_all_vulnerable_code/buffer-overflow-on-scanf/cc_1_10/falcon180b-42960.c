//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Exercise {
    char *name;
    int calories;
};

void print_menu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add exercise\n");
    printf("2. Start workout\n");
    printf("3. View history\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL));
    struct Exercise exercises[100];
    int num_exercises = 0;

    while (1) {
        print_menu();
        int choice = rand() % 4;
        switch (choice) {
            case 0:
                printf("Invalid choice, try again.\n");
                break;
            case 1:
                if (num_exercises >= 100) {
                    printf("Cannot add more exercises.\n");
                } else {
                    char name[20];
                    int calories;
                    printf("Enter exercise name: ");
                    scanf("%s", name);
                    printf("Enter calories burned: ");
                    scanf("%d", &calories);
                    exercises[num_exercises] = (struct Exercise) {.name = name,.calories = calories};
                    num_exercises++;
                }
                break;
            case 2:
                if (num_exercises == 0) {
                    printf("No exercises added, cannot start workout.\n");
                } else {
                    int i;
                    for (i = 0; i < num_exercises; i++) {
                        printf("%s: %d calories\n", exercises[i].name, exercises[i].calories);
                    }
                }
                break;
            case 3:
                if (num_exercises == 0) {
                    printf("No exercises added, no history to view.\n");
                } else {
                    int i;
                    for (i = 0; i < num_exercises; i++) {
                        printf("%s: %d calories\n", exercises[i].name, exercises[i].calories);
                    }
                }
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}
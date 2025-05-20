//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct survivor {
    char *name;
    int expenses;
    int total;
};

int main() {
    int num_survivors;
    printf("How many survivors are in your group?\n");
    scanf("%d", &num_survivors);

    struct survivor *survivors = malloc(sizeof(struct survivor) * num_survivors);
    for (int i = 0; i < num_survivors; i++) {
        survivors[i].name = malloc(20);
        printf("Enter the name of survivor %d:\n", i + 1);
        scanf("%s", survivors[i].name);
        survivors[i].expenses = 0;
        survivors[i].total = 0;
    }

    while (1) {
        int choice;
        printf("Choose an option:\n");
        printf("1. Add an expense\n");
        printf("2. Print expenses\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[20];
                int amount;
                printf("Enter the name of the survivor:\n");
                scanf("%s", name);
                printf("Enter the amount of the expense:\n");
                scanf("%d", &amount);

                int found = 0;
                for (int i = 0; i < num_survivors; i++) {
                    if (strcmp(survivors[i].name, name) == 0) {
                        survivors[i].expenses += amount;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Survivor not found.\n");
                }
                break;
            }

            case 2: {
                for (int i = 0; i < num_survivors; i++) {
                    printf("%s: %d\n", survivors[i].name, survivors[i].expenses);
                }
                break;
            }

            case 3: {
                for (int i = 0; i < num_survivors; i++) {
                    free(survivors[i].name);
                }
                free(survivors);
                exit(0);
            }
        }
    }

    return 0;
}
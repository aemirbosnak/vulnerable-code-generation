//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Tracker {
    char date[11];
    float weight;
    float height;
    float bmi;
    int steps;
    float calories;
} Tracker;

void print_menu() {
    printf("Enter one of the following options:\n");
    printf("1. Add new entry\n");
    printf("2. View previous entries\n");
    printf("3. View overall progress\n");
    printf("4. Exit\n");
}

int main() {
    Tracker entries[100];
    int num_entries = 0;

    while(1) {
        print_menu();

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1: {
                printf("Enter the following details:\n");

                printf("Date: ");
                scanf("%s", entries[num_entries].date);

                printf("Weight (kg): ");
                scanf("%f", &entries[num_entries].weight);

                printf("Height (m): ");
                scanf("%f", &entries[num_entries].height);

                entries[num_entries].bmi = entries[num_entries].weight / (entries[num_entries].height * entries[num_entries].height);

                printf("Number of steps: ");
                scanf("%d", &entries[num_entries].steps);

                printf("Calories consumed: ");
                scanf("%f", &entries[num_entries].calories);

                printf("Entry added successfully!\n");
                num_entries++;
                break;
            }

            case 2: {
                if(num_entries == 0) {
                    printf("No entries found!\n");
                }
                else {
                    printf("Previous entries:\n");
                    printf("%-12s | %-8s | %-8s | %-8s | %-8s | %-8s\n", "Date", "Weight", "Height", "BMI", "Steps", "Calories");
                    printf("----------------------------------------------------------\n");
                    for(int i = 0; i < num_entries; i++) {
                        printf("%-12s | %-8.1f | %-8.1f | %-8.1f | %-8d | %-8.1f\n", entries[i].date, entries[i].weight, entries[i].height, entries[i].bmi, entries[i].steps, entries[i].calories);
                    }
                }
                break;
            }

            case 3: {
                if(num_entries == 0) {
                    printf("No entries found!\n");
                }
                else {
                    float total_weight = 0, total_height = 0, total_bmi = 0, total_steps = 0, total_calories = 0;

                    for(int i = 0; i < num_entries; i++) {
                        total_weight += entries[i].weight;
                        total_height += entries[i].height;
                        total_bmi += entries[i].bmi;
                        total_steps += entries[i].steps;
                        total_calories += entries[i].calories;
                    }

                    float avg_weight = total_weight/num_entries;
                    float avg_height = total_height/num_entries;
                    float avg_bmi = total_bmi/num_entries;
                    int avg_steps = total_steps/num_entries;
                    float avg_calories = total_calories/num_entries;

                    printf("Overall progress:\n");
                    printf("%-8s | %-8s | %-8s | %-8s | %-8s\n", "Weight", "Height", "BMI", "Steps", "Calories");
                    printf("----------------------------------------------------------\n");
                    printf("%-8.1f | %-8.1f | %-8.1f | %-8d | %-8.1f\n", avg_weight, avg_height, avg_bmi, avg_steps, avg_calories);
                }
                break;
            }

            case 4: {
                printf("Exiting program...\n");
                exit(0);
                break;
            }

            default: {
                printf("Invalid option!\n");
                break;
            }
        }
    }
    return 0;
}
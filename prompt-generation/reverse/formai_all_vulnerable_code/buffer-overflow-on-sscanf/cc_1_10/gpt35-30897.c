//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME 50
#define NUM_OF_ELEMENTS 118

typedef struct {
    char name[MAX_NAME];
    char symbol[3];
    int atomic_number;
    float atomic_mass;
} element;

void initialize_element_array(element arr[]);
void print_menu();
void take_quiz(element arr[]);

int main() {
    element element_array[NUM_OF_ELEMENTS];
    initialize_element_array(element_array);
    print_menu();
    take_quiz(element_array);
    return 0;
}

void initialize_element_array(element arr[]) {
    FILE *fp;
    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_NAME];
    int counter = 0;
    while (fgets(buffer, MAX_NAME, fp) != NULL) {
        element new_element;
        sscanf(buffer, "%[^,],%[^,],%d,%f\n", new_element.name, new_element.symbol, &new_element.atomic_number, &new_element.atomic_mass);
        arr[counter] = new_element;
        counter++;
    }

    fclose(fp);
}

void print_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please pick the type of quiz you would like to take:\n");
    printf("1. Symbol to Name\n");
    printf("2. Name to Symbol\n");
}

void take_quiz(element arr[]) {
    int num_correct = 0;
    int num_questions = 0;
    int choice;
    srand(time(0));

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        while (1) {
            int random_index = rand() % NUM_OF_ELEMENTS;
            element current_element = arr[random_index];

            printf("What is the name of the element with symbol %s?\n", current_element.symbol);

            char user_answer[MAX_NAME];
            fgets(user_answer, MAX_NAME, stdin);

            if (strcmp(user_answer, current_element.name) == 0) {
                printf("Correct!\n");
                num_correct++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", current_element.name);
            }

            num_questions++;
            printf("You have answered %d out of %d questions.\n", num_correct, num_questions);
            printf("Would you like to continue? (y/n)\n");

            char continue_answer;
            scanf(" %c", &continue_answer);
            if (continue_answer == 'n') {
                break;
            }
        }
    } else if (choice == 2) {
        while (1) {
            int random_index = rand() % NUM_OF_ELEMENTS;
            element current_element = arr[random_index];

            printf("What is the symbol of the element with name %s?\n", current_element.name);

            char user_answer[3];
            scanf("%s", user_answer);

            if (strcmp(user_answer, current_element.symbol) == 0) {
                printf("Correct!\n");
                num_correct++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", current_element.symbol);
            }

            num_questions++;
            printf("You have answered %d out of %d questions.\n", num_correct, num_questions);
            printf("Would you like to continue? (y/n)\n");

            char continue_answer;
            scanf(" %c", &continue_answer);
            if (continue_answer == 'n') {
                break;
            }
        }
    } else {
        printf("Invalid option. Please try again.\n");
        take_quiz(arr);
    }
}
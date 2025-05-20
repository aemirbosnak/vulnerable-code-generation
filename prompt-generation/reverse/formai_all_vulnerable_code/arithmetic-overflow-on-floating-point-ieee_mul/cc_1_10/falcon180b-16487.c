//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char input[100];
    int choice;
} user_input;

void convert(double, int);
void clear_screen(void);
void get_input(user_input *);
int is_valid_input(char *);

int main() {
    user_input input;
    int choice;

    do {
        clear_screen();
        printf("Welcome to the Temperature Converter!\n");
        printf("Please select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            get_input(&input);

            if (is_valid_input(input.input)) {
                convert(atof(input.input), choice);
            } else {
                printf("Invalid input. Please enter a valid temperature.\n");
            }
        } else if (choice == 3) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice!= 3);

    return 0;
}

void convert(double temp, int choice) {
    double result;

    if (choice == 1) {
        result = (temp * 9/5) + 32;
        printf("%sC is %sF.\n", temp, result);
    } else if (choice == 2) {
        result = (temp - 32) * 5/9;
        printf("%sF is %sC.\n", temp, result);
    }
}

void clear_screen() {
    system("cls");
}

void get_input(user_input *input) {
    printf("Enter a temperature: ");
    scanf("%s", input->input);
    input->choice = 0;
}

int is_valid_input(char *input) {
    int i, j;

    for (i = 0; input[i]!= '\0'; i++) {
        if (!isdigit(input[i]) && input[i]!= '.') {
            return FALSE;
        }
    }

    for (j = 0; input[j]!= '\0'; j++) {
        if (input[j] == '.') {
            if (j == 0 || j == strlen(input) - 1) {
                return FALSE;
            }
            break;
        }
    }

    return TRUE;
}
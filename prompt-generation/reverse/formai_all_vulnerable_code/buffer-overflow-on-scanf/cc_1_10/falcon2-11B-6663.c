//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ELEMENTS 100

int main() {
    int num_elements = 0;
    char name[MAX_NAME_LENGTH][MAX_ELEMENTS];
    int element_idx[MAX_ELEMENTS];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the number of elements you would like to quiz:\n");
    scanf("%d", &num_elements);

    if (num_elements <= 0) {
        printf("Invalid number of elements. Please try again.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; i++) {
        printf("Enter element name: ");
        fgets(name[i], MAX_ELEMENTS, stdin);
        if (strlen(name[i]) > MAX_NAME_LENGTH) {
            printf("Name too long. Please try again.\n");
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (strcmp(name[i], name[j]) == 0) {
                printf("Duplicate element name. Please try again.\n");
                continue;
            }
        }
        element_idx[i] = i;
    }

    printf("Quiz time!\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s (%d)\n", name[i], element_idx[i]);
        printf("Answer:\n");
        scanf("%d", &element_idx[i]);
        if (element_idx[i]!= i) {
            printf("Incorrect answer. Please try again.\n");
        } else {
            printf("Correct!\n");
        }
    }

    return 0;
}
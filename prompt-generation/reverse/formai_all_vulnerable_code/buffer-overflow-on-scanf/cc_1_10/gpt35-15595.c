//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_READINGS 10

void print_list(int* list, int size) {
    printf("[");
    for (int i=0; i<size; i++) {
        printf("%d", list[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int readings[MAX_READINGS] = {0};
    int sum = 0;
    int count = 0;
    printf("Welcome to the temperature monitor.\n");
    printf("Please enter up to 10 temperature readings in Celsius (-273.15 to 1000):\n");
    while (count < MAX_READINGS) {
        int input;
        printf("Reading %d: ", count+1);
        scanf("%d", &input);
        if (input < -273.15 || input > 1000) {
            printf("Invalid temperature, please try again.\n");
            continue;
        }
        readings[count] = input;
        count++;
        sum += input;
        printf("Temperature recorded!\n");
        if (count == MAX_READINGS) {
            printf("Maximum number of readings reached.\n");
        }
        else {
            printf("Would you like to enter another reading? (Y/N): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'N' || choice == 'n') {
                break;
            }
        }
    }
    printf("Here are all the readings:\n");
    print_list(readings, MAX_READINGS);
    float average = sum / (float)count;
    printf("The average temperature is %.2f Celsius.\n", average);
    printf("Thank you for using the temperature monitor!\n");
    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Declare variables
    int age, i, j, k;
    char name[MAX_NAME_LEN];
    char city[MAX_NAME_LEN];
    char country[MAX_NAME_LEN];
    float salary;

    // Print a beautiful header
    printf("----------------------------------------------------------------\n");
    printf("                                                                \n");
    printf("                                      Welcome to My Amazing Program! 😊\n");
    printf("----------------------------------------------------------------\n");
    printf("                                                                \n");
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your city: ");
    fgets(city, MAX_NAME_LEN, stdin);
    printf("Please enter your country: ");
    fgets(country, MAX_NAME_LEN, stdin);
    printf("Your salary is: ");
    salary = (float)rand() / (float)RAND_MAX * 10000;
    printf("%.2f\n", salary);

    // Print a unique pattern
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                if (i * j * k == 0) {
                    printf("🔵");
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }

    // Print a beautiful footer
    printf("----------------------------------------------------------------\n");
    printf("                                                                \n");
    printf("Thank you for using My Amazing Program! 😊\n");
    printf("----------------------------------------------------------------\n");
    return 0;
}
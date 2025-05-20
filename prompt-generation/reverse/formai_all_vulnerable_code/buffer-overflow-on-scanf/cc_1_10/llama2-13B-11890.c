//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Function to read a name and age from the user
void get_name_age(char *name, int *age) {
    printf("Hello, please enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("And your age: ");
    scanf("%d", age);
}

// Function to print a personalized message based on the user's age
void print_message(int age) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char message[50];

    switch (age) {
        case 1:
            sprintf(message, "Happy 1st birthday!");
            break;
        case 18:
            sprintf(message, "Happy 18th birthday!");
            break;
        case 21:
            sprintf(message, "Happy 21st birthday!");
            break;
        case 30:
            sprintf(message, "Happy 30th birthday!");
            break;
        case 50:
            sprintf(message, "Happy 50th birthday!");
            break;
        case 65:
            sprintf(message, "Happy 65th birthday!");
            break;
        case 100:
            sprintf(message, "Happy 100th birthday!");
            break;
        default:
            sprintf(message, "Happy birthday! (%d years old)", age);
            break;
    }
    printf("%s\n", message);
}

int main() {
    char name[MAX_NAME_LEN];
    int age;

    // Get the user's name and age
    get_name_age(name, &age);

    // Print a personalized message based on the user's age
    print_message(age);

    return 0;
}
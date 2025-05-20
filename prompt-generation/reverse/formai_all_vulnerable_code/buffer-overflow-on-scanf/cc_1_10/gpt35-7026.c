//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include<stdio.h>

// define the main function
int main() 
{
    // declare integer variables
    int num1, num2, max;

    // prompt user for inputs
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // determine the maximum number
    max = (num1 > num2) ? num1 : num2;

    // print the maximum number
    printf("The maximum number between %d and %d is %d.", num1, num2, max);

    // Declare a string
    char str[50];

    // Prompt user for input
    printf("\nEnter a string: ");

    // Read input string
    scanf("%s", str);

    printf("\nYou entered: %s", str);

    // Print the length of the string
    printf("\nThe length of the string is %d", strlen(str));

    // Define an array of integers
    int my_array[] = {10, 20, 30, 40, 50};

    // Calculate the length of the array
    int n = sizeof(my_array) / sizeof(my_array[0]);

    // Print the elements of the array
    printf("\nElements of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", my_array[i]);
    }

    // Define a structure
    typedef struct {
        char name[30];
        int age;
        float height;
    } Person;

    // Declare a Person
    Person p;

    // Prompt user for input
    printf("\nEnter your name: ");

    // Read user input
    scanf("%s", p.name);

    printf("Enter your age: ");
    scanf("%d", &p.age);

    printf("Enter your height: ");
    scanf("%f", &p.height);

    // Print the details of the person
    printf("\nName: %s\nAge: %d\nHeight: %0.2f", p.name, p.age, p.height);

    // end the program
    return 0;
}
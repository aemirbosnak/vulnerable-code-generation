//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Function to get input from user
int getInput() {
    int num = 0;
    printf("Please enter the number of terms in the Fibonacci sequence (between 1 and 30): ");
    scanf("%d", &num);
    return num;
}

//Function to calculate Fibonacci sequence
void fibonacci(int num) {
    int a = 0, b = 1, c = 0;
    
    //Print initial values
    printf("%d %d", a, b);
    
    //Calculate and print Fibonacci sequence
    for (int i = 2; i < num; i++) {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
        sleep(1); //Add sleep for visual effect
    }
}

//Function to print colorful text to console
void printColor(char* text, char* color) {
    if (color == "red") {
        printf("\033[1;31m");
    } else if (color == "green") {
        printf("\033[1;32m");
    } else if (color == "yellow") {
        printf("\033[1;33m");
    } else if (color == "blue") {
        printf("\033[1;34m");
    } else if (color == "magenta") {
        printf("\033[1;35m");
    } else if (color == "cyan") {
        printf("\033[1;36m");
    } else if (color == "white") {
        printf("\033[0;37m");
    }
    printf("%s", text);
    printf("\033[0m");
}

int main() {
    printColor("Welcome to the Fibonacci Sequence Visualizer!\n", "green");
    int num = getInput();
    if (num < 1 || num > 30) {
        printColor("Invalid input! Please enter a number between 1 and 30.\n", "red");
        exit(0);
    }
    printColor("Calculating Fibonacci sequence...\n", "cyan");
    fibonacci(num);
    printColor("\nDone!", "magenta");
    return 0;
}
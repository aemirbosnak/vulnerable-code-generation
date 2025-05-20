//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// define the patterns
#define PATTERN1 " *\n"
#define PATTERN2 "*\n *\n"
#define PATTERN3 " *\n*\n*\n"
#define PATTERN4 "*\n *\n*\n *\n"
#define PATTERN5 " *\n*\n *\n"
#define PATTERN6 " *\n *\n"
#define PATTERN7 "*\n *\n*\n"
#define PATTERN8 "*\n *\n *\n"

// function to print the patterns
void print_pattern(int n, char *pattern)
{
    for (int i = 0; i < n; i++)
    {
        printf(pattern);
    }
}

// main function
int main()
{
    int n;

    // prompt the user for the pattern number
    printf("Enter the pattern number (1-8): ");
    scanf("%d", &n);

    // check if the pattern number is valid
    if (n < 1 || n > 8)
    {
        printf("Invalid pattern number.\n");
        return 1;
    }

    // print the selected pattern
    switch (n)
    {
        case 1:
            print_pattern(5, PATTERN1);
            break;
        case 2:
            print_pattern(5, PATTERN2);
            break;
        case 3:
            print_pattern(5, PATTERN3);
            break;
        case 4:
            print_pattern(5, PATTERN4);
            break;
        case 5:
            print_pattern(5, PATTERN5);
            break;
        case 6:
            print_pattern(5, PATTERN6);
            break;
        case 7:
            print_pattern(5, PATTERN7);
            break;
        case 8:
            print_pattern(5, PATTERN8);
            break;
        default:
            printf("Invalid pattern number.\n");
            return 1;
    }

    return 0;
}
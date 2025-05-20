//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

// Function to reverse a string recursively
void reverse_string(char str[], int left_edge, int right_edge)
{
    if (left_edge >= right_edge)
        return;
    else
    {
        // Swap the characters at the left and right edges
        char temp = str[left_edge];
        str[left_edge++] = str[right_edge];
        str[right_edge--] = temp;

        // Recursively call the function with the updated edges
        reverse_string(str, left_edge, right_edge);
    }
}

int main()
{
    char str[100];
    int choice;

    do
    {
        printf("\n1. Input String");
        printf("\n2. Reverse String Recursively");
        printf("\n3. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter a string : ");
                scanf("%s", str);
                break;

            case 2:
                printf("\nString before reversing : %s", str);
                reverse_string(str, 0, strlen(str) - 1);
                printf("\nString after reversing : %s", str);
                break;

            case 3:
                return 0;

            default:
                printf("\nInvalid choice! Try again.");
                break;
        }
    } while (choice != 3);

    return 0;
}
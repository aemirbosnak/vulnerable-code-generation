//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>

// Function to print ASCII Art
void printASCIIArt(int num) {
    switch(num) {
        case 0:
            printf("  ___  \n / _ \\ \n| | | |\n| | | |\n| |_| |\n \\___/ \n");
            break;
        case 1:
            printf(" _ \n/ | \n| |_\n| __|\n| |_\n\\___|\n");
            break;
        case 2:
            printf(" ___  \n|__ \\ \n   ) |\n  / / \n / /_ \n|____|\n");
            break;
        case 3:
            printf(" ____  \n|___ \\ \n  __) |\n |__ < \n ___) |\n|____/ \n");
            break;
        case 4:
            printf(" _  _   \n| || |  \n| || |_ \n|__   _|\n   | |  \n   |_|  \n");
            break;
        case 5:
            printf(" ____  \n| ___| \n|___ \\ \n ___) |\n|____/ \n");
            break;
        case 6:
            printf("  __   \n / /_  \n| '_ \\ \n| (_) |\n \\___/ \n");
            break;
        case 7:
            printf(" ____  \n|___ \\ \n   / / \n  / /  \n / /_  \n|____| \n");
            break;
        case 8:
            printf("  ___  \n / _ \\ \n| (_) |\n > _ < \n| (_) |\n \\___/ \n");
            break;
        case 9:
            printf("  ___  \n / _ \\ \n| (_) |\n \\__, |\n   / / \n  /_/  \n");
            break;
        default:
            printf("Invalid Input. Please enter a number between 0-9.\n");
    }
}

int main() {
    int num;
    char inp[100];

    printf("Enter a number: ");
    fgets(inp, 100, stdin);
    sscanf(inp, "%d", &num);

    printASCIIArt(num);

    return 0;
}
//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>

int main() {

    char input[20];
    printf("Enter a word: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        switch(input[i]) {
            case 'A':
                printf("     ,\n");
                printf(" ,-- | \n");
                printf("<    | \n");
                printf(" `-- | \n");
                printf("     `' \n");
                break;
            case 'B':
                printf(" ,---,\n");
                printf("|  -~-\n");
                printf("| _`_\\\n");
                printf("|  '' |\n");
                printf(" `----'\n");
                break;
            case 'C':
               printf(" ,--,\n");
               printf("/  /,\n");
               printf("|  ||\n");
               printf("\\_/_/\n");
               printf("    ` \n");
               break;
            case 'D':
                printf(",----.\n");
                printf("\\_,-=''\n");
                printf("/__,-.\n");
                printf("   |  \\\n");
                printf("   `-' \n");
                break;
            case 'E':
                printf(" ,--.\n");
                printf("/  .'|\n");
                printf("|  |)\n");
                printf("\\___/ \n");
                printf("      \n");
                break;
            // add more cases for letters and symbols as desired
            default:
                printf("   \n");
                printf(" / )\n");
                printf("( ( \n");
                printf(" \\_) \n");
                printf("  '  \n");
                break;
        }
        i++;
    }
    printf("\n");
    return 0;
}
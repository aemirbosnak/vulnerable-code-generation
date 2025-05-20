//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct {
    char *name;
    int value;
} color_codes[] = {
    {"BLACK", 0},
    {"DARK_BLUE", 1},
    {"DARK_GREEN", 2},
    {"DARK_CYAN", 3},
    {"DARK_RED", 4},
    {"DARK_PINK", 5},
    {"DARK_YELLOW", 6},
    {"GRAY", 7},
    {"DARK_GRAY", 8},
    {"BLUE", 9},
    {"GREEN", 10},
    {"CYAN", 11},
    {"RED", 12},
    {"PINK", 13},
    {"YELLOW", 14},
    {"WHITE", 15}
};

int main() {
    int choice, i = 0;
    char input[100];

    printf("Welcome to the Color Code Converter!\n\n");

    while(1) {
        printf("\nEnter '1' to convert color code to name\n");
        printf("Enter '2' to convert color name to code\n");
        printf("Enter '3' to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the color code: ");
                scanf("%s", input);

                for(i = 0; i < 16; i++) {
                    if(strcmp(color_codes[i].name, input) == 0) {
                        printf("\n%s is %s\n", input, color_codes[i].name);
                        break;
                    }
                }

                if(i == 16) {
                    printf("\nInvalid color code!\n");
                }
                break;

            case 2:
                printf("\nEnter the color name: ");
                scanf("%s", input);

                for(i = 0; i < 16; i++) {
                    if(strcmp(color_codes[i].name, input) == 0) {
                        printf("\n%s is %d\n", input, color_codes[i].value);
                        break;
                    }
                }

                if(i == 16) {
                    printf("\nInvalid color name!\n");
                }
                break;

            case 3:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
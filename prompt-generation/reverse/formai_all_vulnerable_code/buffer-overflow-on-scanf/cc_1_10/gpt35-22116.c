//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    int light_control = 0;
    char choice;

    printf("\nWelcome to our Smart Home System\n");
    printf("===============================================\n");
    printf("Your lights are currently switched off.\n");
    printf("Do you want to switch them on?\n");
    printf("Press Y for yes or N for no\n");
    scanf(" %c", &choice);

    if (toupper(choice) == 'Y' || toupper(choice) == 'N') {
        while (1) {
            switch (toupper(choice)) {
                case 'Y':
                    printf("Your lights have been switched on for a romantic mood\n");
                    light_control = 1;
                    break;
                case 'N':
                    printf("Okay, keeping the lights off\n");
                    light_control = 0;
                    break;
                default:
                    printf("Invalid entry. Please try again\n");
                    break;
            }
            if (light_control == 1) {
                printf("Press T to turn off the lights\n");
                scanf(" %c", &choice);
            } else {
                printf("Press T to turn on the lights\n");
                scanf(" %c", &choice);
            }
            if (toupper(choice) == 'T') {
                if (light_control) {
                    printf("The lights have been switched off\n");
                    light_control = 0;
                } else {
                    printf("Your lights have been switched on for a romantic mood\n");
                    light_control = 1;
                }
                break;
            } else {
                printf("Invalid entry. Please try again\n");
            }
        }
    } else {
        printf("Invalid entry. Please enter only Y or N.\n");
    }
    return 0;
}
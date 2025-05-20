//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I shall guide thee through the mysteries of thy future.\n");
    printf("Choose thy path:\n");
    printf("1. Love\n");
    printf("2. Wealth\n");
    printf("3. Health\n");
    printf("4. Destiny\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Thou seeketh love, eh?\n");
            printf("The cards say...\n");
            printf("Thou shalt find love in the most unexpected of places.\n");
            printf("Keep thine heart open and thine eyes peeled.\n");
            break;
        case 2:
            printf("Wealth thou desireth?\n");
            printf("The cards say...\n");
            printf("Thou shalt come into great fortune soon.\n");
            printf("But beware! For with wealth comes many a foe.\n");
            break;
        case 3:
            printf("Health is thy concern?\n");
            printf("The cards say...\n");
            printf("Thou art blessed with good health.\n");
            printf("Continue to care for thyself and thou shalt live long.\n");
            break;
        case 4:
            printf("Destiny, thou sayest?\n");
            printf("The cards say...\n");
            printf("Thou hast a great journey ahead.\n");
            printf("Many challenges shalt thou face, but fear not!\n");
            printf("For thou art strong and shall overcome all obstacles.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
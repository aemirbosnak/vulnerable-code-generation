//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shapeShift(int num) {
    switch(num) {
        case 1:
            printf("             ,.-~\\\\   \n");
            printf("    /             \\\\\n");
            printf("   |               | \n");
            printf("   |               |\n");
            printf("  \\\\               \\\n");
            printf("   \\\\               \\\n");
            printf("    \\\\               `0_ \\n");
            printf("     \\\\                  \\\n");
            break;
        case 2:
            printf("             ,.-~\\\\   /~-. \n");
            printf("    /            \\\\_\\_");
            printf(" \n");
            printf("   |               _ \\\\__\\ ");
            printf("\n");
            printf("   |\\  ________..-~ / /~_)\n");
            printf("  /_.-~\\     __..--' ||\n");
            printf("        ~~\\\\~~~....__\\/~   \n");
            printf("        (          \\\\\\ \n");
            printf("         \\\\          \\\\\n");
            break;
        case 3:
            printf("                  /~~~-\\__\n");
            printf("             /\\'~)  __~--~     ,--------.\n");
            printf("           (/~~------~         /          \\\n");
            printf("         _//               __/             \\\n");
            printf(" \\\\  _,-'/               /     _______     \\\n");
            printf("  \\\\/  /              ,-'     /-----|   |____\\\n");
            printf("       /_             \\ /     /     _|            \\\n");
            printf("      // \\___--~\\    _//'\\   /___-~   ~~\\_\n");
            printf("     /  / \\_\\    \\\  / ,--|  |_______________\\\n");
            printf("    ((__/(('  \\   \\/___|  /                \n");
            break;
        case 4:
            printf("             _______\n");
            printf("          .-'`       `'-.\n");
            printf("        ,'                `.\n");
            printf("       /                    \\\n");
            printf("      ;     -.                 ;\n");
            printf("      |       `                ;\n");
            printf("      ;                          ;\n");
            printf("       \\                       /\n");
            printf("        `._               _,-'\n");
            printf("           `\"'--.....--'\"'\n");
            break;
        default:
            printf("Oops! Looks like the shape shifting failed.\n");
    }
}

int main() {
    int numOfShapes = 4; // number of different shapes available
    char userName[50]; // to store user's name
    int userAge; // to store user's age

    // getting user information
    printf("Enter your name: ");
    scanf("%s", userName);
    printf("Enter your age: ");
    scanf("%d", &userAge);

    // seed random number generator
    srand(time(NULL));

    // generating random number between 1 to numOfShapes
    int randomNumber = (rand() % numOfShapes) + 1;

    shapeShift(randomNumber); // shape shifting the console

    printf("Hello %s, I am your automated fortune teller.", userName);
    printf("You are %d years old.\n", userAge);
    printf("Your lucky number is %d.\n", randomNumber);
    printf("May good fortune be with you!\n");

    shapeShift(randomNumber); // shape shifting the console again

    return 0;
}
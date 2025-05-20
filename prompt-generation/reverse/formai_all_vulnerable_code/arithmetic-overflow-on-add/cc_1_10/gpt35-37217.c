//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#define PI 3.1415926535

int main() {

    double radius, area, perimeter;
    printf("Welcome, adventurer! I see you're here to find the perimeter and area of a circle. \n");

    do {
        printf("Please enter the radius of the circle: ");
        scanf("%lf", &radius);

        if (radius <= 0) {
            printf("Invalid input. Please enter a positive number. \n");
        }
    } while (radius <= 0);

    perimeter = 2 * PI * radius;
    area = PI * radius * radius;

    printf("You have entered a radius of %f. \n", radius);
    printf("The perimeter of the circle is %.2f units. \n", perimeter);
    printf("The area of the circle is %.2f square units. \n", area);

    printf("But wait! Let me show you something special. \n");
    printf("Do you want to see the circle created from asterisks? (Y/N): ");
    char answer;
    scanf("\n%c", &answer);

    switch(answer) {
        case 'Y':
        case 'y':
            printf("You're in for a treat. Brace yourself! \n");

            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    if ((i * i) + (j * j) <= (radius * radius)) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 'N':
        case 'n':
            printf("Suit yourself. Don't forget to come back soon with another circle! \n");
            break;
        default:
            printf("Invalid input. I'll take that as a no. \n");
            break;
    }

    printf("Thank you for using this program. Have a great day! \n");
    return 0;
}
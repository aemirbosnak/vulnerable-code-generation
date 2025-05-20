//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>

void main() {
    int year, month;

    printf("1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n");
    scanf("%d", &month);
    switch(month) {
        case 1:
            printf("It's January!\n");
            break;
        case 2:
            printf("It's February!\n");
            break;
        case 3:
            printf("It's March!\n");
            break;
        case 4:
            printf("It's April!\n");
            break;
        case 5:
            printf("It's May!\n");
            break;
        case 6:
            printf("It's June!\n");
            break;
        case 7:
            printf("It's July!\n");
            break;
        case 8:
            printf("It's August!\n");
            break;
        case 9:
            printf("It's September!\n");
            break;
        case 10:
            printf("It's October!\n");
            break;
        case 11:
            printf("It's November!\n");
            break;
        case 12:
            printf("It's December!\n");
            break;
        default:
            printf("Invalid input!\n");
            break;
    }
    printf("Thanks for playing!\n");
}
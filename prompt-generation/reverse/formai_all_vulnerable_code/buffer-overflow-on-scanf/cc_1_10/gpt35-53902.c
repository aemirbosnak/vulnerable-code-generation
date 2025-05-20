//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main(){

    int room_number, light_status;
    char ch_1, ch_2;
    printf("Welcome to the Smart Home Light Control program!\n");
    printf("Enter the room number: ");
    scanf("%d", &room_number);
    printf("Room %d is currently ", room_number);
    printf("lit or unlit? (l/u): ");
    scanf(" %c", &ch_1);

    switch(ch_1){
        case 'l':
            light_status = 1;
            printf("Room %d is currently lit.\n", room_number);
            break;
        case 'u':
            light_status = 0;
            printf("Room %d is currently unlit.\n", room_number);
            break;
        default:
            printf("Wrong input! Please try again.\n");
            exit(1);
    }

    printf("Do you want to turn the light on or off? (o/f): ");
    scanf(" %c", &ch_2);

    if (light_status == 1){
        switch(ch_2){
            case 'o':
                printf("The light in Room %d is already on!\n", room_number);
                break;
            case 'f':
                light_status = 0;
                printf("The light in Room %d has been turned off!\n", room_number);
                break;
            default:
                printf("Wrong input! Please try again.\n");
                exit(1);
        }
    } else {
        switch(ch_2){
            case 'o':
                light_status = 1;
                printf("The light in Room %d has been turned on!\n", room_number);
                break;
            case 'f':
                printf("The light in Room %d is already off!\n", room_number);
                break;
            default:
                printf("Wrong input! Please try again.\n");
                exit(1);
        }
    }

    printf("Thank you for using the Smart Home Light Control Program!");
    return 0;
}
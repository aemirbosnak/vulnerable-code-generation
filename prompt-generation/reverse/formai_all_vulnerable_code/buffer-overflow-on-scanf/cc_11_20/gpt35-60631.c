//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>

//define a structure for the light bulb
struct LightBulb {
    int id;
    char location[20];
    int state; //1 is on, 0 is off
};

int main() {
    //create an array of light bulbs
    struct LightBulb bulbs[5];

    //initialize the light bulbs
    bulbs[0].id = 0;
    strcpy(bulbs[0].location, "Living Room");
    bulbs[0].state = 0;
    
    bulbs[1].id = 1;
    strcpy(bulbs[1].location, "Kitchen");
    bulbs[1].state = 0;

    bulbs[2].id = 2;
    strcpy(bulbs[2].location, "Bedroom");
    bulbs[2].state = 0;

    bulbs[3].id = 3;
    strcpy(bulbs[3].location, "Bathroom");
    bulbs[3].state = 0;

    bulbs[4].id = 4;
    strcpy(bulbs[4].location, "Garage");
    bulbs[4].state = 0;
    
    //menu loop
    int choice;
    do {
        //print the menu
        printf("\n-----Smart Home Light Control-----\n");
        printf("Choose an option:\n");
        printf("1. Turn on a light bulb\n");
        printf("2. Turn off a light bulb\n");
        printf("3. View all light bulbs\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                //turn on a light bulb
                printf("\nEnter the id of the light bulb to turn on: ");
                int idOn;
                scanf("%d", &idOn);
                
                //search for the light bulb by id
                int foundOn = 0;
                for(int i = 0; i < 5; i++) {
                    if(bulbs[i].id == idOn) {
                        bulbs[i].state = 1;
                        printf("\n%s turned on.\n", bulbs[i].location);
                        foundOn = 1;
                        break;
                    }
                }
                if(!foundOn)
                    printf("\nLight bulb not found.\n");
                break;
            case 2:
                //turn off a light bulb
                printf("\nEnter the id of the light bulb to turn off: ");
                int idOff;
                scanf("%d", &idOff);
                
                //search for the light bulb by id
                int foundOff = 0;
                for(int i = 0; i < 5; i++) {
                    if(bulbs[i].id == idOff) {
                        bulbs[i].state = 0;
                        printf("\n%s turned off.\n", bulbs[i].location);
                        foundOff = 1;
                        break;
                    }
                }
                if(!foundOff)
                    printf("\nLight bulb not found.\n");
                break;
            case 3:
                //display all light bulbs
                printf("\n-----All Light Bulbs-----\n");
                for(int i = 0; i < 5; i++) {
                    printf("%d. %s is %s\n", bulbs[i].id, bulbs[i].location, bulbs[i].state ? "on" : "off");
                }
                break;
            case 4:
                //exit the program
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
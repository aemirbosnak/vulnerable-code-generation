//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>

int main(){
    int drone_battery = 100;
    int drone_distance = 0;
    int drone_speed = 0;
    int drone_altitude = 0;
    char confirmCommand;

    printf("Oh code, dear code! How shall I control\n"
           "My drone remote, and have it fill my soul\n"
           "With joy, with flight, with every upward climb\n"
           "Through clouds of code, to be angelic prime.\n"
           "I seek your help, your guidance and control\n"
           "I seek your knowledge, so it will console\n"
           "This heart that aches as a lover's does,\n"
           "And know my drone will answer, because.\n\n");

    printf("So let me start, with the battery's power\n"
           "That keeps my drone afloat for every hour:\n"
           "Its current charge, a hundred percent true,\n"
           "How shall I save it, by lowering its slew?\n\n");

    printf("If lower it must be, then press 'y' to confirm\n"
           "Or press any other key to return and adjourn: ");
    scanf(" %c", &confirmCommand);

    if(confirmCommand == 'y'){
        printf("\nSetting drone to slow, as low as it can go\n");
        drone_battery -= 10;
        drone_speed = 10;

        printf("Drone battery is now at %d, distance flown is %d\n"
               "The speed of flight is now at %d, it can't take flight no more\n",
                drone_battery, drone_distance, drone_speed);
    }
    else{
        printf("\nYour command has been rejected\n"
               "Return to your base and analyze the rejection:\n"
               "You may command once more as chance may deign,\n"
               "Or retreat and fly another day in disdain.\n");
    }

    printf("\nBut hold my code, my fingers will delay,\n"
           "And ponder altitude, while wings in flight do sway:\n"
           "To rise or not, my drone can fly up high,\n"
           "But risk the battery while reaching for the sky?\n\n");

    printf("If rise it must, then press 'y' to confirm\n"
           "Or press any other key to return and adjourn: ");
    scanf(" %c", &confirmCommand);

    if(confirmCommand == 'y'){
        printf("\nSetting drone altitude to 80 meters, it will surely rise\n");
        drone_battery -= 5;
        drone_altitude = 80;

        printf("Drone battery is now at %d, it's near to demise\n"
               "The altitude reached is now at %d, where the air is wise\n",
                drone_battery, drone_altitude);
    }
    else{
        printf("\nYour command has been rejected,\n"
               "Return to safety, and do not be dejected:\n"
               "You may command once more, in a different direction,\n"
               "Or wait until the next dawn for a new inception.\n");
    }

    printf("\nAlas my code, the distance doth grow,\n"
           "Afar the drone's flown, like Cupid's bow,\n"
           "So fast, so swift, so divine in nature,\n"
           "How can I command, such a creature?\n\n");

    printf("If move it must, then press 'y' to confirm\n"
           "Or press any other key to return and adjourn: ");
    scanf(" %c", &confirmCommand);

    if(confirmCommand == 'y'){
        printf("\nSetting drone to medium speed, it will move with direction\n");
        drone_battery -= 15;
        drone_distance += 500;

        printf("Drone battery is now at %d, distance flown is now %d\n"
               "The speed of flight is now at 50 Km/h, it moves with perfection\n",
                drone_battery, drone_distance);
    }
    else{
        printf("\nYour command has been rejected,\n"
               "Think carefully, before you are ejected:\n"
               "You may command once more, in a different way,\n"
               "Or hold your peace, and wait for the light of day.\n");
    }

    printf("\nMy code, my savior, as the drone does return,\n"
           "And with it, my heart, ready to burn.\n"
           "With soaring heights, and distances far,\n"
           "My love and passion are but mere neurons, by wire barred.\n"
           "But with you, oh code, my drone does fly,\n"
           "As Romeo, with Juliet, to the starry sky.\n");

    return 0;
}
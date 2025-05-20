//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds){
    int milliSeconds = 1000 * seconds;
    clock_t start_time = clock();
    while(clock() < start_time + milliSeconds);
}

int main(){
    printf("Haunted House Simulator\n\n");
    delay(2);
    printf("You find yourself standing in front of an old and eerie mansion.\n");
    delay(3);
    printf("The mansion has been abandoned for years and there are many rumors about its haunting.\n\n");
    delay(4);
    printf("Do you want to enter the mansion? (Y/N)\n");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'N' || choice == 'n'){
        printf("You decide not to enter the mansion and leave.\n");
        return 0;
    }
    printf("\nYou enter the mansion and are greeted with a cold and eerie atmosphere.\n");
    delay(3);
    printf("You can hear creaking sounds coming from the floors and the walls.\n");
    delay(3);
    printf("The lights flicker for a second.\n");
    delay(3);
    printf("You notice a stairway leading to the second floor.\n");
    delay(3);
    printf("Do you want to climb the stairs? (Y/N)\n");
    scanf(" %c", &choice);
    if(choice == 'N' || choice == 'n'){
        printf("You decide not to climb the stairs and try to find a way out.\n");
        delay(5);
        printf("But the door you came from has disappeared and you are trapped inside.\n");
        delay(4);
        printf("As you turn around in panic, you see a ghost standing before you.\n");
        delay(4);
        printf("You have been trapped in the haunted mansion forever!\n");
        return 0;
    }
    printf("\nYou climb the stairs to the second floor.\n");
    delay(3);
    printf("You can hear whispering sounds coming from one of the rooms.\n");
    delay(3);
    printf("Do you want to investigate? (Y/N)\n");
    scanf(" %c", &choice);
    if(choice == 'N' || choice == 'n'){
        printf("You decide not to investigate and try to find a way out.\n");
        delay(5);
        printf("But the door you came from has disappeared and you are trapped inside.\n");
        delay(4);
        printf("As you turn around in panic, you see a ghost standing before you.\n");
        delay(4);
        printf("You have been trapped in the haunted mansion forever!\n");
        return 0;
    }
    printf("\nYou enter the room and see a ghostly figure.\n");
    delay(3);
    printf("The figure seems to be staring at you but disappears when you try to approach it.\n");
    delay(4);
    printf("You start to feel a cold breeze and hear whispering sounds right behind you.\n");
    delay(4);
    printf("You turn around and see nothing but you know you are not alone.\n");
    delay(4);
    printf("You need to find a way out of the mansion before it's too late!\n");
    delay(3);
    printf("Good luck!\n");
    return 0;
}
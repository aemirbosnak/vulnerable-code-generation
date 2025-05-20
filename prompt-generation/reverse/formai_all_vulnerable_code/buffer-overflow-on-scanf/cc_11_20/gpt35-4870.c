//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Haunted House Simulator!\n");

    int room_num = 1;
    int has_light = 0;

    while(room_num <= 10){

        printf("\nYou are in room %d\n", room_num);

        if(room_num == 1){
            printf("The room is empty except for a candle which is not lit. Do you want to light the candle? (1 for yes, 0 for no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1){
                printf("You lit the candle!\n");
                has_light = 1;
            }
            else{
                printf("You choose not to light the candle.\n");
                has_light = 0;
            }
        }
        else if(room_num == 2){
            printf("You hear some strange noises coming from the closet. Do you want to open it? (1 for yes, 0 for no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1){
                printf("You opened the closet... and found nothing.\n");
            }
            else{
                printf("You choose not to open the closet. Wise choice?\n");
            }
        }
        else if(room_num == 3){
            if(has_light == 1){
                printf("You see a ghostly figure in the corner of the room. Do you want to investigate? (1 for yes, 0 for no)\n");
                int choice;
                scanf("%d", &choice);

                if(choice == 1){
                    printf("You approach the figure... and it disappears into thin air.\n");
                }
                else{
                    printf("You're a wimp! Letting fear get the better of you. Be brave!\n");
                }
            }
            else{
                printf("You cannot see anything in this room without light. Maybe go back to room 1?\n");
            }
        }
        else if(room_num == 4){
            printf("This room is completely dark. Do you have anything that can provide light? (1 for yes, 0 for no)\n");
            int choice;
            scanf("%d", &choice);

            if(choice == 1 && has_light == 1){
                printf("You use your trusted candle to light up the room.\n");
            }
            else if(choice == 1 && has_light == 0){
                printf("You have nothing to provide light. Maybe try to find something in room 1?\n");
            }
            else{
                printf("You choose not to use any kind of light and wander aimlessly in the dark. You stub your toe on something.\n");
            }
        }
        else{
            printf("This room is empty. Keep moving!\n");
        }

        room_num++;
    }

    printf("You have escaped the haunted house! Congratulations!\n");

    return 0;
}
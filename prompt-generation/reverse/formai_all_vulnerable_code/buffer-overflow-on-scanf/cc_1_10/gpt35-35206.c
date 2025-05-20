//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include<stdio.h>

int main(){
    printf("Let's control our cheerful robot!!\n");    // Cheerful message
    
    int ch, speed = 0, distance = 0, angle = 0;    // Initializing variables
    
    while(1){
        // Menu options
        printf("Enter your choice:\n");
        printf("1. Set speed\n");
        printf("2. Set distance\n");
        printf("3. Set angle\n");
        printf("4. Move forward\n");
        printf("5. Stop\n");
        printf("6. Quit\n");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter speed: ");
                scanf("%d", &speed);
                printf("Speed set to %d\n", speed);
                break;
                
            case 2:
                printf("Enter distance: ");
                scanf("%d", &distance);
                printf("Distance set to %d\n", distance);
                break;
                
            case 3:
                printf("Enter angle: ");
                scanf("%d", &angle);
                printf("Angle set to %d\n", angle);
                break;
                
            case 4:
                if(speed == 0){
                    printf("Oops! Please set the speed first.\n");
                }
                else if(distance == 0){
                    printf("Oops! Please set the distance first.\n");
                }
                else{
                    printf("Moving forward with a speed of %d and a distance of %d at an angle of %d\n", speed, distance, angle);
                }
                break;
                
            case 5:
                printf("Stopped!\n");
                break;
                
            case 6:
                printf("Goodbye!!\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
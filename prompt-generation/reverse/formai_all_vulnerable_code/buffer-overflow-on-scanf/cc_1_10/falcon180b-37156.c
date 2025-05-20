//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct fitness{
    int steps;
    int distance;
    int calories;
};

void main(){
    int choice,i,j;
    char name[20];
    struct fitness f[10];
    for(i=0;i<10;i++){
        f[i].steps=0;
        f[i].distance=0;
        f[i].calories=0;
    }
    do{
        printf("\n\nWelcome to the Fitness Tracker in post-apocalyptic world!\n");
        printf("Please enter your name: ");
        scanf("%s",name);
        printf("Welcome %s to the Fitness Tracker in post-apocalyptic world!\n",name);
        printf("Please select an option:\n");
        printf("1. Track steps\n2. Track distance\n3. Track calories\n4. View progress\n5. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number of steps: ");
                scanf("%d",&f[0].steps);
                printf("%s, you have taken %d steps.\n",name,f[0].steps);
                break;
            case 2:
                printf("Enter the distance in meters: ");
                scanf("%d",&f[0].distance);
                printf("%s, you have covered a distance of %d meters.\n",name,f[0].distance);
                break;
            case 3:
                printf("Enter the number of calories burned: ");
                scanf("%d",&f[0].calories);
                printf("%s, you have burned %d calories.\n",name,f[0].calories);
                break;
            case 4:
                printf("\nYour progress so far:\n");
                printf("Steps: %d\n",f[0].steps);
                printf("Distance: %d meters\n",f[0].distance);
                printf("Calories burned: %d\n",f[0].calories);
                break;
            case 5:
                printf("\nThank you for using the Fitness Tracker in post-apocalyptic world, %s!\n",name);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice!=5);
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isLightOn[5] = {false,false,false,false,false};

void turnOnLight(int lightNum){
    if(!isLightOn[lightNum]){
        isLightOn[lightNum] = true;
        printf("Light %d is now turned ON.\n",lightNum);
    }else{
        printf("Light %d is already ON.\n",lightNum);
    }
}

void turnOffLight(int lightNum){
    if(isLightOn[lightNum]){
        isLightOn[lightNum] = false;
        printf("Light %d is now turned OFF.\n",lightNum);
    }else{
        printf("Light %d is already OFF.\n",lightNum);
    }
}

int main(){
    int choice=0;
    int lightNum=0;
    char command[10];

    printf("Welcome to Smart Home Lighting Control System\n");

    while(1){
        printf("\nAvailable Commands: TURN ON | TURN OFF | LIST LIGHTS | EXIT\n");
        printf("Enter your command: ");
        scanf("%s",command);

        if(strcmp(command,"TURN")==0){
            scanf("%s",command);
            if(strcmp(command,"ON")==0){
                printf("Enter Light Number: ");
                scanf("%d",&lightNum);
                if(lightNum<1 || lightNum>5){
                    printf("Invalid Light Number.");
                }else{
                    turnOnLight(lightNum-1);
                }
            }else if(strcmp(command,"OFF")==0){
                printf("Enter Light Number: ");
                scanf("%d",&lightNum);
                if(lightNum<1 || lightNum>5){
                    printf("Invalid Light Number.");
                }else{
                    turnOffLight(lightNum-1);
                }
            }
        }else if(strcmp(command,"LIST")==0){
            printf("List of Lights:\n");
            for(int i=0;i<5;i++){
                printf("Light %d: %s\n",i+1,isLightOn[i]?"ON":"OFF");
            }
        }else if(strcmp(command,"EXIT")==0){
            printf("Exiting Application. Goodbye!");
            break;
        }else{
            printf("Invalid Command.");
        }
    }

    return 0;
}
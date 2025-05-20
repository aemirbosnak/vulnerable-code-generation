//FormAI DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

//function prototype
void switchLights(bool *bedroom, bool *livingroom, bool *kitchen);

int main(){
    
    bool bedroom = false; //initialize bedroom light as off
    bool livingroom = false; //initialize living room light as off
    bool kitchen = false; //initialize kitchen light as off
    
    printf("Welcome to the Smart Home Light Control Program!\n");
    
    int choice;
    bool exit = false; //initialize exit flag as false
    
    while(exit == false){
        printf("\nPlease select an option: \n");
        printf("1. Turn on/off bedroom light\n");
        printf("2. Turn on/off living room light\n");
        printf("3. Turn on/off kitchen light\n");
        printf("4. Exit program\n");
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(bedroom == false){
                    bedroom = true;
                    printf("Bedroom light turned on.\n");
                }
                else{
                    bedroom = false;
                    printf("Bedroom light turned off.\n");
                }
                break;
                
            case 2:
                if(livingroom == false){
                    livingroom = true;
                    printf("Living room light turned on.\n");
                }
                else{
                    livingroom = false;
                    printf("Living room light turned off.\n");
                }
                break;
                
            case 3:
                if(kitchen == false){
                    kitchen = true;
                    printf("Kitchen light turned on.\n");
                }
                else{
                    kitchen = false;
                    printf("Kitchen light turned off.\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit = true;
                break;
            
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
        
        //call function to switch lights based on current states
        switchLights(&bedroom, &livingroom, &kitchen);
    }
    
    return 0;
}

//function definition
void switchLights(bool *bedroom, bool *livingroom, bool *kitchen){
    if(*bedroom == true){
        printf("Bedroom light turned on.\n");
    }
    else{
        printf("Bedroom light turned off.\n");
    }
    
    if(*livingroom == true){
        printf("Living room light turned on.\n");
    }
    else{
        printf("Living room light turned off.\n");
    }
    
    if(*kitchen == true){
        printf("Kitchen light turned on.\n");
    }
    else{
        printf("Kitchen light turned off.\n");
    }
}
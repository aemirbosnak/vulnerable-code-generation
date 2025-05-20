//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdbool.h>

// Function to turn on or off a device
void toggle_device(bool device_status){
    if(device_status){
        printf("Device turned off successfully!\n");
        device_status = false;
    } else{
        printf("Device turned on successfully!\n");
        device_status = true;
    }
}

int main(){
    printf("Welcome to Smart Home Automation!\n");

    bool light_status = false;
    bool fan_status = false;
    bool ac_status = false;

    int user_choice;

    do{
        printf("\n\n1. Toggle Light\n");
        printf("2. Toggle Fan\n");
        printf("3. Toggle AC\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&user_choice);

        switch(user_choice){
            case 1:
                toggle_device(light_status);
                break;

            case 2:
                toggle_device(fan_status);
                break;

            case 3:
                toggle_device(ac_status);
                break;

            case 4:
                printf("Thank you for using Smart Home Automation!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(user_choice!=4);

    return 0;
}
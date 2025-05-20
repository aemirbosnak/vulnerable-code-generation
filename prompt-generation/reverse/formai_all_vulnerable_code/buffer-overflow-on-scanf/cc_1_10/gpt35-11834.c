//FormAI DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

/* Defining a structure for Smart Home Automation */
struct SmartHome {
    int temperature;
    int humidity;
    int light;
    char lock;
};

/* Defining a function to display the current status of the Smart Home */
void displayStatus(struct SmartHome sh) {
    printf("\nCurrent Status:");
    printf("\nTemperature: %d Celsius\t", sh.temperature);
    printf("Humidity: %d percent\n", sh.humidity);
    printf("Light: %d percent\t", sh.light);
    printf("Lock: %c\n", sh.lock);
}

int main() {
    /* Initializing the Smart Home structure with default values */
    struct SmartHome sh = {25, 60, 70, 'L'};
    
    /* Displaying the current status of the Smart Home */
    displayStatus(sh);
    
    /* Taking input from user to change the temperature */
    printf("\nEnter the new temperature value (in Celsius): ");
    scanf("%d", &sh.temperature);
    
    /* Displaying the new status of the Smart Home */
    displayStatus(sh);
    
    /* Taking input from user to change the humidity */
    printf("\nEnter the new humidity value (in percent): ");
    scanf("%d", &sh.humidity);
    
    /* Displaying the new status of the Smart Home */
    displayStatus(sh);
    
    /* Taking input from user to change the light brightness */
    printf("\nEnter the new light brightness (in percent): ");
    scanf("%d", &sh.light);
    
    /* Displaying the new status of the Smart Home */
    displayStatus(sh);
    
    /* Taking input from user to change the lock status */
    printf("\nEnter the new lock status (O to open, C to close): ");
    scanf(" %c", &sh.lock);
    
    /* Displaying the new status of the Smart Home */
    displayStatus(sh);
    
    /* Setting the default values and displaying the new status */
    sh.temperature = 25;
    sh.humidity = 60;
    sh.light = 70;
    sh.lock = 'L';
    printf("\nResetting to default values...");
    displayStatus(sh);
    
    return 0;
}
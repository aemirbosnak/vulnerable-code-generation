//FormAI DATASET v1.0 Category: Physics simulation ; Style: invasive
#include<stdio.h>

int main(){
    
    // Defining Constants
    float pi = 3.14159, g = 9.81;
    
    // Defining Variables
    float mass, radius, height, force, energy, velocity, time = 0;
    int choice;
    
    // Menu for User Input
    printf("Welcome to Physics Simulation! Choose an option below to get started.\n");
    printf("1. Fall Simulation\n");
    printf("2. Roll Simulation\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            // Fall Simulation
            printf("Enter mass of object (in kg): ");
            scanf("%f", &mass);
            printf("Enter height of object (in m): ");
            scanf("%f", &height);
            
            // Calculations
            force = mass * g;
            energy = mass * g * height;
            velocity = 0;
            
            // Print Results
            printf("\nResults:\n");
            printf("Force: %.2f N\n", force);
            printf("Energy: %.2f J\n", energy);
            while(height > 0){
                height -= (velocity * time) + (0.5 * g * time * time);
                velocity += g * time;
                time += 0.1;
                if(height < 0){
                    height = 0;
                }
                printf("Height: %.2f m\tVelocity: %.2f m/s\n", height, velocity);
            }
            break;
        
        case 2:
            // Roll Simulation
            printf("Enter mass of object (in kg): ");
            scanf("%f", &mass);
            printf("Enter radius of object (in m): ");
            scanf("%f", &radius);
            
            // Calculations
            velocity = 0;
            time = 0;
            
            // Print Results
            printf("\nResults:\n");
            while(radius > 0){
                force = mass * g;
                radius -= (velocity * time) + (0.5 * g * time * time);
                velocity += (force / mass) * time;
                time += 0.1;
                if(radius < 0){
                    radius = 0;
                }
                printf("Radius: %.2f m\tVelocity: %.2f m/s\n", radius, velocity);
            }
            break;
        
        case 3:
            // Exit Program
            printf("Exiting Program...");
            break;
        
        default:
            // Invalid Choice
            printf("Invalid Choice!");
            break;
    }
    
    return 0;
}
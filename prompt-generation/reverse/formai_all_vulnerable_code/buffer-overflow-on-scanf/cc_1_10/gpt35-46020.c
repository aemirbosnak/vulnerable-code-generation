//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 

void *car_simulator(void *arg);
void *remote_control(void *arg);

int main() 
{ 
    pthread_t car_thread, controller_thread; 
    
    pthread_create(&car_thread, NULL, car_simulator, NULL); 
    pthread_create(&controller_thread, NULL, remote_control, NULL); 
    
    pthread_join(car_thread, NULL); 
    pthread_join(controller_thread, NULL); 
    
    return 0; 
}

void *car_simulator(void *arg) 
{ 
    int speed = 0;
    int direction = 0;
    
    while (1) 
    { 
        printf("Speed: %d, Direction: %d\n", speed, direction); 
  
        // simulate car movement 
        usleep(500000);
        
        // update car speed and direction 
        if (speed < 100) 
            speed += 10;
        
        if (speed >= 100 && speed < 150) 
            speed += 5;
        
        if (speed >= 150) 
            speed -= 10;
        
        direction = rand() % 21 - 10;
    } 
    
    pthread_exit(NULL); 
} 

void *remote_control(void *arg) 
{ 
    int speed = 0;
    char direction_input;
    
    while (1) 
    { 
        printf("Enter direction [L/R] and speed [0-9]: "); 
        scanf(" %c%d", &direction_input, &speed);
        
        if (direction_input == 'L') 
            printf("Turning left\n");
        
        else if (direction_input == 'R') 
            printf("Turning right\n");
        
        // check speed input 
        if (speed < 0) 
            speed = 0;
        
        else if (speed > 9) 
            speed = 9;
        
        printf("Setting speed to %d\n", speed * 10);
    } 
    
    pthread_exit(NULL); 
}
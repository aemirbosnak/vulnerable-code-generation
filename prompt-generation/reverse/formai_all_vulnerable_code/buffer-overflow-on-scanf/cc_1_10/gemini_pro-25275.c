//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of lights
#define NUM_LIGHTS 5

// Define the light states
#define LIGHT_ON 1
#define LIGHT_OFF 0

// Define the light control commands
#define LIGHT_CMD_ON 1
#define LIGHT_CMD_OFF 0

// Define the thread attributes
pthread_attr_t attr;

// Define the mutex
pthread_mutex_t mutex;

// Define the condition variable
pthread_cond_t cond;

// Define the light states
int light_states[NUM_LIGHTS];

// Define the light control commands
int light_commands[NUM_LIGHTS];

// Define the thread function
void *light_control_thread(void *arg)
{
    int light_num = (int)arg;

    while (1)
    {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Wait for a command
        while (light_commands[light_num] == 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        // Get the command
        int command = light_commands[light_num];

        // Update the light state
        if (command == LIGHT_CMD_ON)
        {
            light_states[light_num] = LIGHT_ON;
        }
        else if (command == LIGHT_CMD_OFF)
        {
            light_states[light_num] = LIGHT_OFF;
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Print the light state
        printf("Light %d is now %s\n", light_num + 1, light_states[light_num] ? "on" : "off");
    }

    return NULL;
}

// Define the main function
int main()
{
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the condition variable
    pthread_cond_init(&cond, NULL);

    // Initialize the thread attributes
    pthread_attr_init(&attr);

    // Create the light control threads
    pthread_t threads[NUM_LIGHTS];
    for (int i = 0; i < NUM_LIGHTS; i++)
    {
        pthread_create(&threads[i], &attr, light_control_thread, (void *)i);
    }

    // Send commands to the light control threads
    while (1)
    {
        // Get a command
        int command;
        printf("Enter a command (0 to exit): ");
        scanf("%d", &command);

        if (command == 0)
        {
            break;
        }

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Send the command to all the lights
        for (int i = 0; i < NUM_LIGHTS; i++)
        {
            light_commands[i] = command;
        }

        // Signal the condition variable
        pthread_cond_broadcast(&cond);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    // Join the light control threads
    for (int i = 0; i < NUM_LIGHTS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Destroy the condition variable
    pthread_cond_destroy(&cond);

    // Destroy the thread attributes
    pthread_attr_destroy(&attr);

    return 0;
}
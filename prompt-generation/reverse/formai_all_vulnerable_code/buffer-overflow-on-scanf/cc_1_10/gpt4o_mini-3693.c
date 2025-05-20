//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_COLOR_CODES 100
#define COLOR_CODE_LENGTH 8 // #FFFFFF
#define RGB_LENGTH 20 // "R: 255, G: 255, B: 255"

// Structure to hold color input data
typedef struct {
    char hexColor[COLOR_CODE_LENGTH];
    char rgbColor[RGB_LENGTH];
} ColorData;

// Queue to store color codes for conversion
ColorData colorQueue[MAX_COLOR_CODES];
int queueIndex = 0;
pthread_mutex_t queueMutex;

// Function to convert Hexadecimal color code to RGB
void* convertColor(void* arg) {
    ColorData* colorData = (ColorData*)arg;
    int r, g, b;

    // Convert hex to decimal RGB
    if (sscanf(colorData->hexColor, "#%02x%02x%02x", &r, &g, &b) == 3) {
        sprintf(colorData->rgbColor, "R: %d, G: %d, B: %d", r, g, b);
    } else {
        snprintf(colorData->rgbColor, RGB_LENGTH, "Invalid Hex");
    }
    
    printf("Converted %s to %s\n", colorData->hexColor, colorData->rgbColor);
    pthread_exit(NULL);
}

// Function to queue color codes for conversion
void queueColorCode(const char* hexColor) {
    pthread_mutex_lock(&queueMutex);
    
    if (queueIndex < MAX_COLOR_CODES) {
        strncpy(colorQueue[queueIndex].hexColor, hexColor, COLOR_CODE_LENGTH);
        colorQueue[queueIndex].hexColor[COLOR_CODE_LENGTH - 1] = '\0';
        queueIndex++;
    } else {
        printf("Color queue is full! Cannot add %s\n", hexColor);
    }
    
    pthread_mutex_unlock(&queueMutex);
}

// Function to process the color conversion queue
void* processQueue(void* arg) {
    while (1) {
        pthread_mutex_lock(&queueMutex);
        
        if (queueIndex > 0) {
            // Get the color to convert
            queueIndex--;
            ColorData colorData = colorQueue[queueIndex];
            pthread_mutex_unlock(&queueMutex);
            
            // Perform and print color conversion
            convertColor((void*)&colorData);
        } else {
            pthread_mutex_unlock(&queueMutex);
        }
        
        sleep(1); // Only process every second to simulate async behavior
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t processorThread;
    pthread_mutex_init(&queueMutex, NULL);
    
    // Start the queue processor
    pthread_create(&processorThread, NULL, processQueue, NULL);

    char input[COLOR_CODE_LENGTH];
    
    printf("Enter hex color codes (e.g., #FFFFFF), type 'exit' to quit:\n");
    
    while (1) {
        printf("Hex Color: ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        queueColorCode(input);
    }

    // Clean up
    pthread_cancel(processorThread);
    pthread_join(processorThread, NULL);
    pthread_mutex_destroy(&queueMutex);

    printf("Exiting the program.\n");
    return 0;
}
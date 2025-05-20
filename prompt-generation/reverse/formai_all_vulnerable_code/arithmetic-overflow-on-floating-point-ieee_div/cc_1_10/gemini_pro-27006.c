//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the connection
float initConnection() {
    // Generating a random number between 0 and 1
    float connectionSpeed = 0.0 + (1.0 - 0.0) * ((float) rand() / (float) RAND_MAX);
    // Just to make it prettier
    printf("Kissing the wires... (%f%%)\n", connectionSpeed * 100);
    return connectionSpeed;
}

// Send the test data
int sendData(float connectionSpeed) {
    // Assuming 100 bytes of data
    int dataSize = 100;
    int timeElapsed = dataSize / connectionSpeed;
    printf("Sending you sweet nothings (%d bytes)... \n", dataSize);
    printf("Took me %d seconds to express how much I love you.\n", timeElapsed);
    return timeElapsed;
}

// Receive the test data
int receiveData(int timeElapsed) {
    printf("Receiving your love letters... Took you %d seconds.\n", timeElapsed);
    return timeElapsed;
}

// Calculate the Internet speed
float calculateSpeed(int sendTime, int receiveTime) {
    float speed = (200.0 / (float)(sendTime + receiveTime));
    return speed;
}

// Display the results
void displayResults(float speed) {
    printf("Our Internet love speed is: %.2f bytes/second\n", speed);
    printf("I hope you're as happy as I am!\n");
}

int main() {
    // Seeding the random number generator
    srand(time(NULL));
    
    // Get the connection speed
    float connectionSpeed = initConnection();

    // Send the data
    int sendTime = sendData(connectionSpeed);

    // Receive the data
    int receiveTime = receiveData(sendTime);

    // Calculate the Internet speed
    float speed = calculateSpeed(sendTime, receiveTime);

    // Display the results
    displayResults(speed);

    return 0;
}
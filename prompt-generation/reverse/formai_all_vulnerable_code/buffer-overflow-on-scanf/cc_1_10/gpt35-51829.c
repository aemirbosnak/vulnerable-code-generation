//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int disks;  
pthread_mutex_t mutex;  

void moveDisk(char fromTower, char toTower, int disk) {
    printf("Move disk %d from %c to %c\n", disk, fromTower, toTower);
    return;
}

void* towerOfHanoi(void* rod) {  
    int disk = disks;  
    char currRod = (char)((int)*(char*)rod);  
    char bufferRod = *(char*)malloc(sizeof(char));  
    int intermediateRod = 6 - (int)currRod - (int)bufferRod;  
    while (disk != 0) {
        pthread_mutex_lock(&mutex);  
        moveDisk(currRod, bufferRod, disk);  
        disk--;  
        pthread_mutex_unlock(&mutex);
        pthread_mutex_lock(&mutex);  
        moveDisk(currRod, intermediateRod+64, disk);  
        disk--;  
        pthread_mutex_unlock(&mutex);
        pthread_mutex_lock(&mutex);  
        moveDisk(bufferRod, currRod, disk);  
        disk--;  
        pthread_mutex_unlock(&mutex);
        bufferRod = currRod;  
        currRod = (char)((int)6 - (int)currRod - (int)bufferRod);  
    }  
    return NULL;  
}  

int main() {
    printf("Enter number of disks: ");
    scanf("%d", &disks);
    pthread_t t1, t2, t3;  

    pthread_create(&t1, NULL, towerOfHanoi, (void*)&"A");  
    pthread_create(&t2, NULL, towerOfHanoi, (void*)&"B");  
    pthread_create(&t3, NULL, towerOfHanoi, (void*)&"C");  

    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  
    pthread_join(t3, NULL);  

    return 0;  
}
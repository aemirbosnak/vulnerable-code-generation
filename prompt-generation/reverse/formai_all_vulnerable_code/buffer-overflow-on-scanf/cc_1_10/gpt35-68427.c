//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
/* 
    Digital Auction System Example Program 
    By: [Your Name]

    Description: This program simulates a digital auction system where multiple users can bid    
    on an item until the auction time runs out. The user with the highest bid at the end of
    the auction wins the item. The program uses multithreading to handle multiple user bids 
    at the same time.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 10    // Maximum number of users
#define TIME_LIMIT 30   // Auction time limit in seconds
#define ITEM_NAME "Smartphone" // Name of the item to be auctioned

// User data structure
typedef struct {
    int id;         // User ID
    int bid;        // Latest bid made by the user
    int status;     // Status of the user - 0: inactive, 1: active
} User;

User users[MAX_USERS];  // Array of users
int highest_bid;        // Highest bid made so far
pthread_mutex_t mutex;  // Mutex for thread synchronization

// Thread function for user bidding
void *bid_on_item(void *arg) {
    int user_id = *(int *)arg;
    printf("User %d is now active.\n", user_id);
    while(users[user_id].status) {
        int bid_amount = rand() % 1000;
        sleep(1);   // Wait for 1 second before placing another bid
        pthread_mutex_lock(&mutex);
        if(users[user_id].status && users[user_id].bid < bid_amount && bid_amount > highest_bid) {
            printf("User %d has placed a bid of %d.\n", user_id, bid_amount);
            highest_bid = bid_amount;
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("User %d has stopped.\n", user_id);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t threads[MAX_USERS];
    pthread_mutex_init(&mutex, NULL);
    int num_users;
    printf("Enter the number of users (maximum %d): ", MAX_USERS);
    scanf("%d", &num_users);
    if(num_users < 1 || num_users > MAX_USERS) {
        printf("Invalid number of users.\n");
        return 0;
    }
    printf("Starting auction for %s. Auction time is %d seconds.\n", ITEM_NAME, TIME_LIMIT);
    for(int i=0; i<num_users; i++) {
        users[i].id = i+1;
        users[i].bid = 0;
        users[i].status = 1;
        pthread_create(&threads[i], NULL, bid_on_item, &users[i].id);
    }
    sleep(TIME_LIMIT);  // Wait for the auction time to finish
    for(int i=0; i<num_users; i++) {
        users[i].status = 0;
        pthread_join(threads[i], NULL); // Wait for all threads to exit
    }
    printf("Auction for %s has ended. Highest bid is %d.\n", ITEM_NAME, highest_bid);
    pthread_mutex_destroy(&mutex);
    return 0;
}
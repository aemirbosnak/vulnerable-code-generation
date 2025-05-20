//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_SIZE 1024 * 1024 // 1MB

int main() {
    struct timeval start, end;
    int sockfd, n;
    char *buffer;
    struct hostent *host;

    printf("Welcome to the Crazy Internet Speed Test!\n");
    printf("Get ready to laugh and test your internet like a boss!\n");
    
    host = gethostbyname("google.com");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Oops, something went wrong! Can't create a socket.\n");
        return 1;
    }

    printf("Connected to Google like a ninja!\n");

    buffer = malloc(MAX_SIZE);
    if (buffer == NULL) {
        printf("Oops, out of memory! Try again when you're less hungry.\n");
        return 1;
    }

    printf("Downloading a massive file... hold on tight!\n");
    
    gettimeofday(&start, NULL);
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    gettimeofday(&end, NULL);

    if (n == -1) {
        printf("Oops, something went wrong during the download! Maybe Google is having a dance party?\n");
        return 1;
    }

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = (double)n / elapsed;

    printf("Woohoo! Download complete!\n");
    printf("Your internet speed is %f Mbps.\n", speed / 1000000.0);

    if (speed > 10) {
        printf("You're a speed demon! Zoom, zoom!\n");
    } else if (speed > 5) {
        printf("Not bad! You can stream some kittens without buffering.\n");
    } else {
        printf("Ouch! Your internet is slower than a sloth on a unicycle.\n");
    }

    printf("Thanks for playing the Crazy Internet Speed Test! Come back for more laughs and speed tests!\n");
    
    free(buffer);
    close(sockfd);

    return 0;
}
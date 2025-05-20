//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 10 // maximum number of threads allowed
#define MAX_URLS 50 // maximum number of URLs that can be tested
#define BUFFER_SIZE 1024 // buffer size for reading URLs and results

// shared data structures
char urls[MAX_URLS][BUFFER_SIZE]; // array of URLs to test
double results[MAX_URLS]; // array of test results for each URL
int num_urls = 0; // number of URLs in the urls array

// thread function for testing a URL's speed
void *test_speed(void *arg)
{
    int index = *(int *)arg; // get the index of the URL to test
    char command[BUFFER_SIZE]; // command for running the speed test
    char result[BUFFER_SIZE]; // buffer for reading the speed test results
    double speed; // the actual speed in Mbps

    // construct the command for running the speed test
    snprintf(command, BUFFER_SIZE, "speedtest-cli --simple --url=%s | awk '/Download/ {print $2}'", urls[index]);

    // open a pipe for running the command
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        fprintf(stderr, "Error opening pipe for URL %s: %s\n", urls[index], strerror(errno));
        pthread_exit(NULL);
    }

    // read the speed test results from the pipe
    if (fgets(result, BUFFER_SIZE, pipe) != NULL) {
        sscanf(result, "%lf", &speed);
        results[index] = speed;
    } else {
        fprintf(stderr, "Error reading speed test results from URL %s\n", urls[index]);
    }

    // close the pipe and exit the thread
    pclose(pipe);
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[MAX_THREADS]; // array of thread handles
    int indices[MAX_THREADS]; // array of indices for each thread

    // read the URLs from standard input and store in the urls array
    for (i = 0; i < MAX_URLS; i++) {
        if (fgets(urls[i], BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        urls[i][strlen(urls[i])-1] = '\0'; // remove the newline character
    }
    num_urls = i;

    // create a thread for each URL to test
    for (i = 0; i < num_urls; i++) {
        if (i >= MAX_THREADS) {
            fprintf(stderr, "Maximum number of threads exceeded, only testing first %d URLs\n", i);
            break;
        }
        indices[i] = i;
        if (pthread_create(&threads[i], NULL, test_speed, &indices[i]) != 0) {
            fprintf(stderr, "Error creating thread for URL %s: %s\n", urls[i], strerror(errno));
        }
    }

    // wait for all threads to finish
    for (i = 0; i < num_urls && i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread for URL %s: %s\n", urls[i], strerror(errno));
        }
    }

    // print the results
    printf("\nResults:\n\n");
    for (i = 0; i < num_urls; i++) {
        if (i >= MAX_THREADS) {
            break;
        }
        printf("%s: %.2f Mbps\n", urls[i], results[i]);
    }

    return 0;
}
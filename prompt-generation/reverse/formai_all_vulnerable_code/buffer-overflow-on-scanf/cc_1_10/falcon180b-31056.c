//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 100

struct request {
    int id;
    char hex[8];
    char rgb[10];
};

void *process_request(void *arg) {
    struct request *request = (struct request *) arg;

    char red[3], green[3], blue[3];
    sprintf(red, "%02X", request->hex[0] >> 4 & 0x0F);
    sprintf(green, "%02X", request->hex[0] & 0x0F);
    sprintf(blue, "%02X", request->hex[1] >> 4 & 0x0F);

    sprintf(request->rgb, "RGB (%s, %s, %s)", red, green, blue);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct request requests[MAX_REQUESTS];
    int num_threads = 0;
    int num_requests = 0;

    while (num_requests < MAX_REQUESTS) {
        printf("Enter a hex color code (or press enter to stop): ");
        scanf("%s", requests[num_requests].hex);

        if (requests[num_requests].hex[0] == '\n') {
            break;
        }

        num_requests++;
    }

    for (int i = 0; i < num_requests; i++) {
        pthread_create(&threads[num_threads], NULL, process_request, &requests[i]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
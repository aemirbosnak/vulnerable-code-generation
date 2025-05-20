//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // for multi-threading
#include <sys/types.h>
#include <sys/sysinfo.h> // for system info
#include <time.h>

#define NUM_THREADS 4 // number of threads to create

void *print_cpu_usage(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Thread %ld reporting for duty!\n", tid);
    while(1)
    {
        // get system information
        struct sysinfo si;
        if(sysinfo(&si) != 0)
        {
            printf("sysinfo: error\n");
        }
    
        // calculate CPU usage
        unsigned long long total_time = si.totalram - si.freeram;
        float usage = 100.0 - ((float) si.freeram / si.totalram) * 100.0;
        
        // display CPU usage
        printf("Thread %ld CPU Usage: %.2f%%\n", tid, usage);
        
        // sleep for a random amount of time
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }
    pthread_exit(NULL);
}

int main ()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    srand(time(NULL)); // initialize random seed
    
    for(t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %ld...\n", t);
        rc = pthread_create(&threads[t], NULL, print_cpu_usage, (void *)t);
        if (rc)
        {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
}
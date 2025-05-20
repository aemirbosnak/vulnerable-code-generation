//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

#define URL "http://speedtest.net/speedtest-files/10MB.bin"
#define NUM_TESTS 5
#define TEST_SECONDS 10

typedef struct {
    CURL *curl;
    FILE *fp;
} SpeedTestContext;

int init_speed_test(SpeedTestContext *ctx) {
    ctx->curl = curl_easy_init();
    if (!ctx->curl)
        return -1;
    
    ctx->fp = fopen("speedtest.bin", "wb");
    if (!ctx->fp)
        return -1;
    
    curl_easy_setopt(ctx->curl, CURLOPT_URL, URL);
    curl_easy_setopt(ctx->curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(ctx->curl, CURLOPT_WRITEDATA, ctx->fp);
    
    return 0;
}

void cleanup_speed_test(SpeedTestContext *ctx) {
    if (ctx->curl)
        curl_easy_cleanup(ctx->curl);
    
    if (ctx->fp)
        fclose(ctx->fp);
}

int run_speed_test(SpeedTestContext *ctx) {
    double speed;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    curl_easy_perform(ctx->curl);
    gettimeofday(&end, NULL);
    
    speed = (double)(10 * 8) / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
    printf("Speed: %.2f Mbps\n", speed);
    
    return 0;
}

int main() {    
    SpeedTestContext ctx;
    int i;
    
    if (init_speed_test(&ctx) < 0) {
        fprintf(stderr, "Error initializing speed test\n");
        return -1;
    }
    
    for (i = 0; i < NUM_TESTS; i++) {
        printf("Running test %d\n", i + 1);
        if (run_speed_test(&ctx) < 0) {
            fprintf(stderr, "Error running speed test\n");
            return -1;
        }
        sleep(TEST_SECONDS);
    }
    
    cleanup_speed_test(&ctx);
    
    return 0;
}
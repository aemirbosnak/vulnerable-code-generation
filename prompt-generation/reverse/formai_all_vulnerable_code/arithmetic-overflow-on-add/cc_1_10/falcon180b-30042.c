//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_QR_SIZE 4096

typedef struct {
    int id;
    char *data;
    int data_len;
    int is_qr;
} QRCode;

typedef struct {
    int count;
    QRCode *codes[MAX_QR_SIZE];
} QRThreadData;

void *qr_thread(void *arg) {
    QRThreadData *data = (QRThreadData *)arg;
    QRCode *qrcode = data->codes[data->count];

    if (qrcode->is_qr) {
        printf("QR Code detected with data: %s\n", qrcode->data);
    } else {
        printf("Barcode detected with data: %s\n", qrcode->data);
    }

    data->count++;
    if (data->count >= MAX_QR_SIZE) {
        pthread_exit(0);
    }
}

int main() {
    pthread_t threads[MAX_THREADS];
    QRThreadData thread_data;
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, qr_thread, &thread_data);
    }

    while (1) {
        QRCode qrcode;
        int ret = scanf("%d %s %d", &qrcode.id, qrcode.data, &qrcode.data_len);

        if (ret!= 3) {
            break;
        }

        if (thread_data.count >= MAX_QR_SIZE) {
            printf("Maximum QR codes reached.\n");
            continue;
        }

        if (qrcode.data_len > MAX_QR_SIZE - 1) {
            printf("QR code data too large.\n");
            continue;
        }

        thread_data.codes[thread_data.count] = &qrcode;
        thread_data.count++;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
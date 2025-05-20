//FormAI DATASET v1.0 Category: QR code reader ; Style: multivariable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QRCode {
    int x;
    int y;
    char* data;
} QRCode;

QRCode* create_QRCode(int x, int y, char* data) {
    QRCode* qr = malloc(sizeof(QRCode));
    qr->x = x;
    qr->y = y;
    qr->data = strdup(data);
    return qr;
}

void destroy_QRCode(QRCode* qr) {
    free(qr->data);
    free(qr);
}

typedef struct QRCodeContainer {
    int count;
    QRCode** codes;
} QRCodeContainer;

QRCodeContainer* create_QRCodeContainer() {
    QRCodeContainer* container = malloc(sizeof(QRCodeContainer));
    container->count = 0;
    container->codes = NULL;
    return container;
}

void destroy_QRCodeContainer(QRCodeContainer* container) {
    for (int i = 0; i < container->count; ++i) {
        destroy_QRCode(container->codes[i]);
    }
    free(container->codes);
    free(container);
}

QRCode* decode_QRCode(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    char buf[256];
    if (!fgets(buf, 256, file)) {
        fclose(file);
        return NULL;
    }

    int x, y;
    char* data = NULL;
    sscanf(buf, "%d %d", &x, &y);

    while (fgets(buf, 256, file)) {
        data = realloc(data, strlen(data) + strlen(buf) + 1);
        strcat(data, buf);
    }

    fclose(file);

    QRCode* qr = create_QRCode(x, y, data);
    free(data);
    return qr;
}

void add_QRCode(QRCodeContainer* container, QRCode* qr) {
    container->count++;
    container->codes = realloc(container->codes, container->count * sizeof(QRCode*));
    container->codes[container->count - 1] = qr;
}

int main(int argc, char** argv) {
    QRCodeContainer* container = create_QRCodeContainer();

    for (int i = 1; i < argc; ++i) {
        QRCode* qr = decode_QRCode(argv[i]);
        if (qr) add_QRCode(container, qr);
    }

    for (int i = 0; i < container->count; ++i) {
        QRCode* qr = container->codes[i];
        printf("QRCode %d x=%d y=%d data=%s\n", i, qr->x, qr->y, qr->data);
    }

    destroy_QRCodeContainer(container);
    return 0;
}
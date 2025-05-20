//FormAI DATASET v1.0 Category: QR code generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>
#include <pthread.h>

#define MAX_DATA_SIZE 1000
#define QR_CODE_SIZE 10

void *generate_qr_code(void* qr_data);

int main(int argc, char *argv[]) {

  char data[MAX_DATA_SIZE];
  pthread_t thread;

  if(argc < 2) {
    printf("Please enter data to store in QR code: ");
    fgets(data, MAX_DATA_SIZE, stdin);
    data[strlen(data) - 1] = '\0';
  }
  else {
    strncpy(data, argv[1], MAX_DATA_SIZE);
  }

  if(pthread_create(&thread, NULL, generate_qr_code, (void*)data)) {
      printf("Error creating thread\n");
      return 1;
    }

  pthread_join(thread, NULL);

  return 0;
}

void *generate_qr_code(void* qr_data) {
  QRcode *qr_code = QRcode_encodeString((char*)qr_data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

  int qr_width = qr_code->width;
  unsigned char **qr_matrix = qr_code->data;
  int i, j;

  for(i = 0; i < qr_width*QR_CODE_SIZE; i++) {
    for(j = 0; j < qr_width*QR_CODE_SIZE; j++) {
      if(qr_matrix[i/QR_CODE_SIZE][j/QR_CODE_SIZE] & 1) {
        printf("##");
      }
      else {
        printf("  ");
      }
    }
    printf("\n");
  }

  QRcode_free(qr_code);

  pthread_exit(NULL);
}
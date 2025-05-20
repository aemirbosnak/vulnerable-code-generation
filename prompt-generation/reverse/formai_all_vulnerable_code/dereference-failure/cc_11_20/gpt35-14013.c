//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define the key length
#define KEYLEN 16

// define the maximum message size
#define MAXMSGLEN 1000

int main()
{
  // read the input image file
  FILE *input = fopen("input.bmp", "rb");
  if (input == NULL)
  {
    printf("Error: Could not open input file.\n");
    return 1;
  }

  // read the image header
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, input);

  // read the image data
  unsigned char *data = (unsigned char *)malloc(sizeof(unsigned char) * (header[18] * header[22] * 3 + header[34]));
  fread(data, sizeof(unsigned char), header[34], input);

  // close the input file
  fclose(input);

  // generate the key
  unsigned char key[KEYLEN];
  for (int i = 0; i < KEYLEN; i++)
  {
    key[i] = rand() % 256;
  }

  // read the message from the user
  printf("Enter the message to be embedded: ");
  char message[MAXMSGLEN];
  fgets(message, MAXMSGLEN, stdin);
  message[strcspn(message, "\n")] = '\0';

  // check if the message is too big for the image
  int msglen = strlen(message) + 1;
  int imglen = header[18] * header[22] * 3;
  if (msglen > imglen)
  {
    printf("Error: Message too big for the image.\n");
    return 1;
  }

  // embed the message
  for (int i = 0; i < msglen; i++)
  {
    unsigned char byte = message[i];
    for (int j = 0; j < 8; j++)
    {
      int bit = (byte >> j) & 1;
      int pos = i * 8 + j;

      // embed the bit by modifying the least significant bit of the pixel
      if (bit == 1)
      {
        if (data[pos] % 2 == 0)
        {
          data[pos]++;
        }
      }
      else
      {
        if (data[pos] % 2 == 1)
        {
          data[pos]--;
        }
      }
    }
  }

  // embed the key
  int keypos = msglen * 8;
  for (int i = 0; i < KEYLEN; i++)
  {
    unsigned char byte = key[i];
    for (int j = 0; j < 8; j++)
    {
      int bit = (byte >> j) & 1;
      int pos = keypos + i * 8 + j;

      // embed the bit by modifying the least significant bit of the pixel
      if (bit == 1)
      {
        if (data[pos] % 2 == 0)
        {
          data[pos]++;
        }
      }
      else
      {
        if (data[pos] % 2 == 1)
        {
          data[pos]--;
        }
      }
    }
  }

  // write the watermarked image to disk
  FILE *output = fopen("output.bmp", "wb");
  if (output == NULL)
  {
    printf("Error: Could not open output file.\n");
    return 1;
  }
  fwrite(header, sizeof(unsigned char), 54, output);
  fwrite(data, sizeof(unsigned char), header[34], output);
  fclose(output);

  // extract the watermark
  unsigned char *watermark = (unsigned char *)malloc(sizeof(unsigned char) * KEYLEN);
  for (int i = 0; i < KEYLEN; i++)
  {
    unsigned char byte = 0;
    for (int j = 0; j < 8; j++)
    {
      int bitpos = msglen * 8 + i * 8 + j;
      int bit = data[bitpos] % 2;
      byte |= (bit << j);
    }
    watermark[i] = byte;
  }

  // compare the extracted watermark with the original key
  int errors = 0;
  for (int i = 0; i < KEYLEN; i++)
  {
    if (watermark[i] != key[i])
    {
      errors++;
    }
  }

  if (errors == 0)
  {
    printf("Watermark successfully embedded and extracted.\n");
  }
  else
  {
    printf("Error: Watermark extraction failed.\n");
  }

  free(data);
  free(watermark);
  return 0;
}
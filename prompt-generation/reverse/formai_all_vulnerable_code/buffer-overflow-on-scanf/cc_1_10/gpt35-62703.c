//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include<stdio.h>
#include<string.h>

void encode(char *image_name, char *message);
void decode(char *image_name);

int main()
{
	char image_name[20];
	char message[1000];
	int choice;

	printf("\t\t===========================================\n");
	printf("\t\t|\t  Image Steganography Program \t|\n");
	printf("\t\t===========================================\n\n");

	printf("Enter the image file name to encode the message: ");
	scanf("%s", image_name);

	printf("Enter the message to encode in the image: ");
	getchar();
	fgets(message, 1000, stdin);
	
	printf("\nEncoding the message...\nPlease wait...\n\n");
	
	encode(image_name, message);
	
	printf("\nThe message has been encoded successfully!!!\n\n");
	
	printf("Do you want to decode the message from the image? (1 for Yes/0 for No): ");
	scanf("%d", &choice);
	
	if(choice == 1)
	{
		printf("\nDecoding the message from the image...\nPlease wait...\n\n");
		
		decode(image_name);
	}
	else
	{
		printf("\nThank you for using Image Steganography Program.\n");
	}

	return 0;
}

void encode(char *image_name, char *message)
{
	FILE *fp_image, *fp_encoded;
	char ch;
	int i = 0, bit_index = 0, byte_index = 0;
	unsigned char byte, encoded_byte = 0, mask;

	fp_image = fopen(image_name, "rb");
	fp_encoded = fopen("encoded_image.bmp", "wb");

	if(fp_image == NULL)
	{
		printf("Error: Failed to open image file\n");
		return;
	}

	if(fp_encoded == NULL)
	{
		printf("Error: Failed to create encoded image file\n");
		return;
	}

	while((ch = fgetc(fp_image)) != EOF)
	{
		if(byte_index < 54)
		{
			fputc(ch, fp_encoded);
			byte_index++;
		}
		else
		{
			byte = (unsigned char) ch;

			for(i = 0; i < 8; i++)
			{
				mask = (1 << bit_index);

				if((int) message[byte_index - 54] & mask) // check whether the bit is 0 or 1 in the message
				{
					encoded_byte |= mask; // set the bit to 1 in the encoded byte
				}
				else
				{
					encoded_byte &= ~mask; // set the bit to 0 in the encoded byte
				}

				bit_index++;

				if(bit_index == 8) // when all 8 bits are set in the encoded byte
				{
					fputc(encoded_byte, fp_encoded); // write the encoded byte to the encoded image file
					byte_index++;
					bit_index = 0;
					encoded_byte = 0;
				}
			}

			fputc(byte, fp_encoded); // write the original byte to the encoded image file
		}
	}

	fclose(fp_image);
	fclose(fp_encoded);
}

void decode(char *image_name)
{
	FILE *fp_encoded, *fp_decoded;
	char ch;
	int i = 0, bit_index = 0, byte_index = 0;
	unsigned char byte, decoded_byte = 0, mask;

	fp_encoded = fopen("encoded_image.bmp", "rb");
	fp_decoded = fopen("decoded_message.txt", "w");

	if(fp_encoded == NULL)
	{
		printf("Error: Failed to open encoded image file\n");
		return;
	}

	if(fp_decoded == NULL)
	{
		printf("Error: Failed to create decoded message file\n");
		return;
	}

	fseek(fp_encoded, 54, SEEK_SET); // skip the header of the BMP image file

	while((ch = fgetc(fp_encoded)) != EOF)
	{
		byte = (unsigned char) ch;

		for(i = 0; i < 8; i++)
		{
			mask = (1 << bit_index);

			if(byte & mask) // check whether the bit is 0 or 1 in the decoded byte
			{
				decoded_byte |= mask; // set the bit to 1 in the decoded byte
			}
			else
			{
				decoded_byte &= ~mask; // set the bit to 0 in the decoded byte
			}

			bit_index++;

			if(bit_index == 8) // when all 8 bits are set in the decoded byte
			{
				if((char) decoded_byte == '\0') // check for end of message character ('\0')
				{
					fclose(fp_encoded);
					fclose(fp_decoded);

					printf("\nThe message has been decoded successfully!!!\n\n");

					printf("\n\n The decoded message is romantic and goes like this: \n");
					printf("\t  \"My love for you is like a hidden message in an image, \n");
					printf("\t  It's invisible to the world but only visible to you,\n");
					printf("\t  And just like how this message is stored in bits, \n");
					printf("\t  My love for you is stored deep in my heart forever.\"\n\n");

					return;
				}

				fprintf(fp_decoded, "%c", decoded_byte); // write the decoded byte to the decoded message file
				byte_index++;
				bit_index = 0;
				decoded_byte = 0;
			}
		}
	}

	fclose(fp_encoded);
	fclose(fp_decoded);
}
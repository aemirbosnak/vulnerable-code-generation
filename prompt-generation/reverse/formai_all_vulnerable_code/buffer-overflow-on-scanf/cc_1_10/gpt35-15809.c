//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 256

typedef struct node{
    int freq;
    unsigned char c;
    struct node *left, *right;
}Node;

typedef struct heap{
    int size;
    int capacity;
    Node **arr;
}Heap;

Node* newNode(int freq, unsigned char c){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->c = c;
    temp->freq = freq;
    return temp;
}

Heap* createHeap(int capacity){
    Heap *temp = (Heap*)malloc(sizeof(Heap));
    temp->size = 0;
    temp->capacity = capacity;
    temp->arr = (Node**)malloc(sizeof(Node*) * capacity);
    return temp;
}

void swap(Node **a, Node **b){
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap *heap, int idx){
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;

    if(right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;

    if(smallest != idx){
        swap(&heap->arr[smallest], &heap->arr[idx]);
        heapify(heap, smallest);
    }
}

Node* extractMin(Heap *heap){
    Node *temp = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size-1];
    --heap->size;
    heapify(heap, 0);

    return temp;
}

void insertHeap(Heap *heap, Node *node){
    ++heap->size;

    int idx = heap->size - 1;
    while(idx && node->freq < heap->arr[(idx-1)/2]->freq){
        heap->arr[idx] = heap->arr[(idx-1)/2];
        idx = (idx-1)/2;
    }
    heap->arr[idx] = node;
}

int isLeaf(Node *node){
    return !(node->left) && !(node->right);
}

Heap* buildHeap(char *str){
    int *freq = (int*)calloc(MAX_CHARS,sizeof(int));
    int i,n = strlen(str);

    for(i = 0; i < n; ++i)
        freq[str[i]]++;
    
    Heap *heap = createHeap(MAX_CHARS);
    for(i = 0; i < MAX_CHARS; ++i)
        if(freq[i])
            insertHeap(heap, newNode(freq[i], i));
    free(freq);
    return heap;
}

Node* buildHuffmanTree(char *str){
    Heap *heap = buildHeap(str);
    while(heap->size > 1){
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);

        Node *node = newNode(left->freq + right->freq, 0);
        node->left = left;
        node->right = right;

        insertHeap(heap, node);
    }
    return extractMin(heap);
}

void encode(Node *root, char *str, int idx, char *code[]){
    if(root->left){
        str[idx] = '0';
        encode(root->left, str, idx+1, code);
    }

    if(root->right){
        str[idx] = '1';
        encode(root->right, str, idx+1, code);
    }

    if(isLeaf(root)){
        str[idx] = '\0';
        code[root->c] = strdup(str);
    }
}

void compressFile(char *src, char *dst){
    FILE *fptrIn = fopen(src, "r");
    char ch;
    char *str = (char*)malloc(MAX_CHARS*sizeof(char));
    int n = 0;

    while((ch=fgetc(fptrIn))!= EOF){
        str[n++] = ch;
    }
    str[n] = '\0';
    Node *root = buildHuffmanTree(str);
    char *code[MAX_CHARS] = {};
    encode(root, str, 0, code);

    FILE *fptrOut = fopen(dst, "w");
    fputs(root->c,fptrOut);
    for(int i=0;i<MAX_CHARS;i++){
        if(code[i] != NULL){
            fprintf(fptrOut,"%c%s",i,code[i]);
        }
    }

    fseek(fptrIn,0,SEEK_SET);

    int bitCount = 0;
    char byte = 0;
    while((ch=fgetc(fptrIn))!= EOF){
        char *bits = code[ch];
        int i=0;
        while(bits[i++]){
            if(bitCount == 8){
                fputc(byte,fptrOut);
                bitCount = 0;
                byte = 0;
            }
            bitCount++;
            byte = byte << 1;
            if(bits[i-1] == '1'){
                byte |= 1;
            }
        }
    }

    if(bitCount > 0){
        byte <<= (8-bitCount);
        fputc(byte,fptrOut);
    }

    fclose(fptrIn);
    fclose(fptrOut);
    printf("\nFile compressed successfully!\n");
}

void decompressFile(char *src, char *dst){
    FILE *fptrIn = fopen(src, "r");
    FILE *fptrOut = fopen(dst, "w");

    char ch;
    ch = fgetc(fptrIn);
    Node* root = newNode(0, ch);

    while((ch = fgetc(fptrIn)) != EOF){
        char c = ch;
        ch = fgetc(fptrIn);

        char *str = (char*)malloc(MAX_CHARS*sizeof(char));
        int i = 0;
        while(ch != '\n'){
            str[i++] = ch;
            ch = fgetc(fptrIn);
        }
        str[i] = '\0';

        Node* current = root;
        for(int j=0;j<i;j++){
            if(str[j] == '0'){
                if(current->left == NULL){
                    current->left = newNode(0,0);
                }
                current = current->left;
            }else{
                if(current->right == NULL){
                    current->right = newNode(0,0);
                }
                current = current->right;
            }
        }
        current->c = c;
        free(str);
    }

    Node *current = root;
    int bitCount = 0;
    char byte = fgetc(fptrIn);
    while(byte != EOF){
        for(int i = 7; i >= 0; i--){
            if(current->c != 0){
                fputc(current->c, fptrOut);
                current = root;
            }
            if(byte & (1 << i)){
                current = current->right;
            }else{
                current = current->left;
            }

            if(current == NULL){
                break;
            }
        }
        bitCount++;
        if(bitCount == 8){
            byte = fgetc(fptrIn);
            bitCount = 0;
        }
    }

    fclose(fptrIn);
    fclose(fptrOut);
    printf("\nFile decompressed successfully!\n");
}

int main(){
    int choice;
    char fName[20],cName[20],dName[20];

    while(1){
        printf("Enter your choice:\n1. Compress file\n2. Decompress file\n3. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter file to compress: ");
                scanf("%s",fName);
                sprintf(cName, "%s_compressed.txt", fName);
                compressFile(fName, cName);
                break;
            case 2:
                printf("Enter file to decompress: ");
                scanf("%s",cName);
                printf("Enter name for decompressed file: ");
                scanf("%s",dName);
                decompressFile(cName, dName);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}